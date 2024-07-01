#include <Utils.hpp>
#include <fstream>

std::string Utils::replace(std::string search, std::string replace, std::string input)
{
    size_t index;
    std::string result(input);

    while ((index = result.find(search)) != std::string::npos)
    {
        std::string s1 = result.substr(0, index);
        std::string s2 = result.substr(index + search.size());

        result = s1 + replace + s2;
    }

    return result;
}

void Utils::create_replace_file(std::string path)
{
    std::fstream file(path.c_str(), std::ios::in);
    if (file.fail()) {
        return;
    }
    std::ofstream result((path + ".replace").c_str());
    std::string buffer;

    while(std::getline(file, buffer))
    {
        result << buffer;
        if (!file.eof()) {
            result << std::endl;
        }
    }
    result.close();
}
