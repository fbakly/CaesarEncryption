#include <sys/stat.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

void printHelp() {
    std::cout << "\n\t./caesar -[option] [filename] [key]\n\n";
    std::cout << "\tOptions :\n";
    std::cout << "\t\te to encrypt\n";
    std::cout << "\t\td to decrypt\n";
    std::cout << "\n\tEx.. ./caesar -e example.txt 15\n\n";
}

bool isValidOption(char **argv) {
    return (std::strcmp("-e", argv[1]) == 0 || std::strcmp("-d", argv[1]) == 0);
}

bool isValidKey(char **argv) {
    auto cont = true;
    auto isValid = true;
    for (auto index = 0; argv[3][index] && cont; index++) {
        if (!std::isdigit(argv[3][index])) {
            cont = false;
            isValid = false;
        }
    }
    return isValid;
}

std::string encrypt(char **argv) {
    if (auto inputFile = std::ifstream{argv[2]}; !inputFile) {
        return "Failure";
    } else {
        auto option = argv[1];
        auto key = std::stoi(argv[3]);
        auto lineRead = std::string{};
        auto encryptedString = std::ostringstream{};

        if (key > 26)
            key %= 26;
        auto numKey = (key > 10) ? key % 10 : key;
        while (std::getline(inputFile, lineRead)) {
            for (auto index = 0; lineRead[index]; index++) {
                if (lineRead[index] + key > 'z' && islower(lineRead[index]))
                    lineRead[index] = 'a' + (key - ('z' - lineRead[index] - 1) - 2);
                else if (lineRead[index] + key > 'Z' && isupper(lineRead[index]))
                    lineRead[index] = 'A' + (key - ('Z' - lineRead[index] - 1) - 2);
                else if (isalpha(lineRead[index]))
                    lineRead[index] += key;
                else if (isdigit(lineRead[index])) {
                    if (lineRead[index] + numKey > '0')
                        lineRead[index] = '0' + (numKey - ('9' - lineRead[index] - 1) - 2);
                    else
                        lineRead[index] += numKey;
                }
            }
            encryptedString << lineRead;
        }
        inputFile.close();
        return encryptedString.str();
    }
    return "Invalid parameters";
}

std::string decrypt(char **argv) {
    if (auto inputFile = std::ifstream{argv[2]}; !inputFile) {
        return "Failure";
    } else {
        auto option = argv[1];
        auto key = std::stoi(argv[3]);
        auto lineRead = std::string{};
        auto encryptedString = std::ostringstream{};

        if (key > 26)
            key %= 26;
        auto numKey = (key > 10) ? key % 10 : key;
        while (std::getline(inputFile, lineRead)) {
            for (auto index = 0; lineRead[index]; index++) {
                if (lineRead[index] - key < 'a' && islower(lineRead[index]))
                    lineRead[index] = 'z' - (key - (lineRead[index] - 'a') - 1);
                else if (lineRead[index] - key < 'A' && isupper(lineRead[index]))
                    lineRead[index] = 'Z' - (key - (lineRead[index] - 'A') - 1);
                else if (isalpha(lineRead[index]))
                    lineRead[index] -= key;
                else if (isdigit(lineRead[index])) {
                    if (lineRead[index] - numKey < '0')
                        lineRead[index] = '9' - (numKey - (lineRead[index] - '0') - 1);
                    else
                        lineRead[index] -= numKey;
                }
            }
            encryptedString << lineRead;
        }
        inputFile.close();
        return encryptedString.str();
    }
    return "Invalid parameters";
}

void writeToFile(std::string encryptedString) {
    if (encryptedString != "Failure" && encryptedString != "Invalid parameters") {
        auto index = 0;
        auto exists = false;
        auto outputFileName = std::string{"output"};

        do {
            if (index > 0) {
                outputFileName.clear();
                outputFileName.append("output_" + std::to_string(index));
            }
            struct stat bf;
            if (stat(outputFileName.c_str(), &bf) == 0)
                exists = true;
            else
                exists = false;
            index++;
        } while (exists);
        auto outputFile = std::ofstream{outputFileName};
        outputFile << encryptedString;
        outputFile.close();
    } else {
        std::cout << encryptedString << "\n";
    }
}

void process(char **argv) {
    if (isValidKey(argv) && isValidOption(argv)) {
        if (std::strcmp(argv[1], "-e") == 0)
            writeToFile(encrypt(argv));
        else
            writeToFile(decrypt(argv));
    }
}

int main(int argc, char **argv) {
    switch (argc) {
        case 1:
            printHelp();
            break;
        case 2:
            if (std::strcmp("-h", argv[1]) == 0 || std::strcmp("--help", argv[1]) == 0)
                printHelp();
            else
                goto DEFAULT;
            break;
        case 4:
            process(argv);
            break;
        DEFAULT:
        default:
            std::cout << "Invalid number of argument\n";
            break;
    }
}