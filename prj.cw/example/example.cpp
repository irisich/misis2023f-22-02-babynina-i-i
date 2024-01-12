#include <clocale>
#include "contentChecker/contentChecker.hpp"

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    FileParser fileParser;

    if (argc < 2 || argc > 4) {
        std::cout << "Usage: parser file.txt [log.txt]\n";
        return 0;
    }

    std::cout << "Hello world!" << std::endl;

    std::string logFileName = (argc == 3) ? argv[2] : "";

    fileParser.processFile(argv[1], logFileName);

    std::cout << "End of world!" << std::endl;

    return 0;
}