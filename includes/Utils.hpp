#ifndef UTILS_H
# define UTILS_H

#include <string>

class Utils {
    public:
        static std::string replace(std::string, std::string, std::string);
        static void create_replace_file(std::string path);
};

#endif
