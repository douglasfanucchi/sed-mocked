#ifndef UTILS_H
# define UTILS_H

#include <string>

class Utils {
    public:
        static std::string replace(std::string, std::string, std::string);
        static void createReplaceFile(std::string path);
};

#endif
