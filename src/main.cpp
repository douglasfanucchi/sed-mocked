#include <fstream>
#include <Utils.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 4) {
        std::cerr << "Invalid number of arguments." << std::endl;
        return 1;
    }

    std::string buffer;
    std::string result("");
    std::fstream f(argv[1], std::ios::in);
    if (!f) {
        std::cerr << "Invalid filename." << std::endl;
        return 1;
    }

    Utils::createReplaceFile(argv[1]);
    while (std::getline(f, buffer))
    {
        result += Utils::replace(argv[2], argv[3], buffer);
        if (!f.eof()) {
            result += '\n';
        }
    }
    f.close();
    f.open(argv[1], std::ios::out);
    if (!f) {
        std::cerr << "Invalid filename." << std::endl;
        return 1;
    }
    f << result;
    f.close();
    return 0;
}
