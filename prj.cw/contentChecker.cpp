#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <cctype>
#include <algorithm>
#include "contentChecker/contentChecker.hpp"

// Статический метод для считывания строки из потока
std::string StringUtilities::readstr(std::istream& input) {
    std::string s;
    std::getline(input, s);
    return s;
}

// Статический метод для проверки, является ли строка числом
bool StringUtilities::isNumber(const std::string& s) {
    if (s.empty())
        return 0;

    bool isn = 1;
    for (auto& i : s)
    {
        if (i < 0 || !std::isdigit(i))
        {
            isn = 0;
            break;
        }
    }
    return isn;
}

// Статический метод для извлечения числовой части строки
std::string StringUtilities::getNumberPart(const std::string& s) {
    std::string res;
    for (std::size_t i = 0; i < s.length(); ++i)
    {
        char part = s.at(i);
        if (std::isdigit(part)) {
            res += part;
        }
    }
    return res;
}

// Статический метод для парсинга имени, извлечение номера, если присутствует
std::string StringUtilities::parseName(std::string name) {
    int number = -1;
    if (name.substr(0, 22) == "Практическая работа № " || name.substr(0, 23) == "Практическое занятие № ") {
        number = std::stoi(getNumberPart(name.substr(22)));
    }
    if (number != -1) {
        return "Практическая работа №" + std::to_string(number);
    }
    while (!name.empty() && name.back() >= 0 && !std::isalpha(name.back()) && !std::isdigit(name.back())) {
        name.pop_back();
    }
    return name;
}


// Конструктор класса
FileParser::FileParser() : line(0) {}

// Метод для считывания строки из потока
bool FileParser::read(std::istream& input, std::string& s)
{
    if (getline(input, s))
    {
        bool isn = true;
        for (auto& i : s)
        {
            if (i < 0 || !isdigit(i))
            {
                isn = false;
                break;
            }
        }
        if (isn && std::stoi(s) <= this->line + 2)
            this->line = std::stoi(s);
        if (isn)
            getline(input, s);
        return true;
    }
    return false;
}

// Метод для парсинга строки и извлечения информации
bool FileParser::parse(const std::string& line, std::pair<std::string, int>& res) {
    std::string numval = StringUtilities::getNumberPart(line);
    if (!StringUtilities::isNumber(numval)) {
        return false;
    }
    res = { StringUtilities::parseName(line.substr(0, line.size() - numval.size() - 1)), std::stoi(numval) };
    return true;
}

// Метод для проверки блока текста
bool FileParser::block(const std::string& s) {
    std::stringstream ss(s);
    std::string tmp;
    int words = 0;
    while (ss >> tmp) {
        words++;
    }
    return words <= 4 && words >= 1 && s.size() <= 100 && (s[0] < 0 || std::isupper(s[0]));
}

// Метод для обработки содержимого файла
void FileParser::processFile(const std::string& fileName, const std::string& logFileName) {
    std::ifstream fileStream;
    std::ofstream logStream;

    fileStream.open(fileName);


    if (!fileStream.is_open()) {
        std::cout << "Error: cannot read file " << fileName << std::endl;
        return;
    }

    if (!logFileName.empty()) {
        logStream.open(logFileName);
        if (!logStream.is_open()) {
            std::cout << "Error: cannot open log file " << logFileName << std::endl;
            fileStream.close();
            return;
        }
        std::cout << "Log redirected to " << logFileName << std::endl;
        std::cout.rdbuf(logStream.rdbuf());
    }

    std::string l;
    while (read(fileStream, l) && l.substr(0, 10) != "Оглавление" && l.substr(0, 10) != "Содержание") {
        // Ничего не делать, пропустить строки до оглавления
    }

    if (line == 0) {
        std::cout << "No line numbers found. Numbers check is disabled\n";
    }

    if (l.substr(0, 10) != "Оглавление" && l.substr(0, 10) != "Содержание") {
        std::cout << "Не найдено оглавление. Проверьте, что в файле есть строка \"Оглавление\" или \"Содержание\"";
        fileStream.close();
        logStream.close();
        return;
    }

    std::map<std::string, int> head;

    while (read(fileStream, l)) {
        std::pair<std::string, int> t;

        if (!parse(l, t)) {
            break;
        }

        if (head.count(StringUtilities::parseName(l))) {
            break;
        }

        head.insert(t);
    }

    std::vector<std::pair<std::string, int>> lst2;

    do {
        lst2.emplace_back(StringUtilities::parseName(l), line);
    } while (read(fileStream, l));

    for (auto& i : lst2) {
        if (!head.count(i.first)) {
            // std::cout << "Блок \"" << i.first << "\" из файла не найден в оглавлении * " << std::endl;
        }
        else if (i.second != head[i.first]) {
            std::cout << "Блок \"" << i.first << "\" в содержании указан с неверным номером страницы\n" << "(Номер в оглавлении " << head[i.first] << " Номер в файле " << i.second << ")\n";
            head.erase(i.first);
        }
        else {
            head.erase(i.first);
        }
    }

    for (auto& i : head) {
        std::cout << "Блок \"" << i.first << "\" из оглавления не найден в файле\n";
    }

    std::cout << "ОК" << std::endl;

    fileStream.close();
    logStream.close();
}
