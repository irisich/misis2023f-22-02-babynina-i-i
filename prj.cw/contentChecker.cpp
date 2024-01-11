#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <cctype>
#include <algorithm>
#include "contentChecker/contentChecker.hpp"

// ����������� ����� ��� ���������� ������ �� ������
std::string StringUtilities::readstr(std::istream& input) {
    std::string s;
    std::getline(input, s);
    return s;
}

// ����������� ����� ��� ��������, �������� �� ������ ������
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

// ����������� ����� ��� ���������� �������� ����� ������
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

// ����������� ����� ��� �������� �����, ���������� ������, ���� ������������
std::string StringUtilities::parseName(std::string name) {
    int number = -1;
    if (name.substr(0, 22) == "������������ ������ � " || name.substr(0, 23) == "������������ ������� � ") {
        number = std::stoi(getNumberPart(name.substr(22)));
    }
    if (number != -1) {
        return "������������ ������ �" + std::to_string(number);
    }
    while (!name.empty() && name.back() >= 0 && !std::isalpha(name.back()) && !std::isdigit(name.back())) {
        name.pop_back();
    }
    return name;
}


// ����������� ������
FileParser::FileParser() : line(0) {}

// ����� ��� ���������� ������ �� ������
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

// ����� ��� �������� ������ � ���������� ����������
bool FileParser::parse(const std::string& line, std::pair<std::string, int>& res) {
    std::string numval = StringUtilities::getNumberPart(line);
    if (!StringUtilities::isNumber(numval)) {
        return false;
    }
    res = { StringUtilities::parseName(line.substr(0, line.size() - numval.size() - 1)), std::stoi(numval) };
    return true;
}

// ����� ��� �������� ����� ������
bool FileParser::block(const std::string& s) {
    std::stringstream ss(s);
    std::string tmp;
    int words = 0;
    while (ss >> tmp) {
        words++;
    }
    return words <= 4 && words >= 1 && s.size() <= 100 && (s[0] < 0 || std::isupper(s[0]));
}

// ����� ��� ��������� ����������� �����
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
    while (read(fileStream, l) && l.substr(0, 10) != "����������" && l.substr(0, 10) != "����������") {
        // ������ �� ������, ���������� ������ �� ����������
    }

    if (line == 0) {
        std::cout << "No line numbers found. Numbers check is disabled\n";
    }

    if (l.substr(0, 10) != "����������" && l.substr(0, 10) != "����������") {
        std::cout << "�� ������� ����������. ���������, ��� � ����� ���� ������ \"����������\" ��� \"����������\"";
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
            // std::cout << "���� \"" << i.first << "\" �� ����� �� ������ � ���������� * " << std::endl;
        }
        else if (i.second != head[i.first]) {
            std::cout << "���� \"" << i.first << "\" � ���������� ������ � �������� ������� ��������\n" << "(����� � ���������� " << head[i.first] << " ����� � ����� " << i.second << ")\n";
            head.erase(i.first);
        }
        else {
            head.erase(i.first);
        }
    }

    for (auto& i : head) {
        std::cout << "���� \"" << i.first << "\" �� ���������� �� ������ � �����\n";
    }

    std::cout << "��" << std::endl;

    fileStream.close();
    logStream.close();
}
