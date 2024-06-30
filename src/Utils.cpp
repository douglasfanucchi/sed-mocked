#include <Utils.hpp>

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
