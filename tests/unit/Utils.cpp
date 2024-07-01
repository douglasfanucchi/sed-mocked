#include <Utils.hpp>
#include <asserts.hpp>
#include <fstream>
#include <iterator>
#include <algorithm>

void test_should_replace_hello_world_by_ola_mundo()
{
    std::string input = "This phrase contains hello world";
    std::string expected = "This phrase contains ola mundo";

    std::string result = Utils::replace("hello world", "ola mundo", input);

    ASSERT_STREQ(expected, result);
}

void test_should_not_do_nothing_when_search_word_is_present_in_the_string()
{
    std::string input = "This phrase doesn't contain any word to replace";
    std::string expected = "This phrase doesn't contain any word to replace";

    std::string result = Utils::replace("hello", "hey", input);

    ASSERT_STREQ(expected, result);
}

void test_should_replace_multiple_recurrences()
{
    std::string input = "This line contains multiple hello world, hello world!";
    std::string expected = "This line contains multiple ola mundo, ola mundo!";

    std::string result = Utils::replace("hello world", "ola mundo", input);

    ASSERT_STREQ(expected, result);
}

void test_should_copy_a_file_and_its_name_should_be_its_original_name_dot_replace()
{
    std::fstream file("tests/files/lorem-ipsum.txt", std::ios::in);
    std::string expected;
    int expectedLines = std::count(std::istream_iterator<char>(file >> std::noskipws), {}, '\n');

    Utils::create_replace_file("tests/files/lorem-ipsum.txt");

    std::fstream resultFile("tests/files/lorem-ipsum.txt.replace");
    int resultLines = std::count(std::istream_iterator<char>(resultFile >> std::noskipws), {}, '\n');
    while (std::getline(file, expected)) {
        std::string result;
        std::getline(resultFile, result);

        ASSERT_STREQ(expected, result);
    }
    ASSERT_EQ(expectedLines, resultLines);
}

void test_should_not_create_replace_file_when_original_file_doesnt_exist()
{
    Utils::create_replace_file("tests/files/non-existent-file.txt");

    std::fstream result("tests/files/non-existent-file.txt.replace");
    ASSERT_TRUE(result.fail());
}

void RUN_UTILS_SUITE()
{
    test_should_replace_hello_world_by_ola_mundo();
    test_should_not_do_nothing_when_search_word_is_present_in_the_string();
    test_should_replace_multiple_recurrences();
    test_should_copy_a_file_and_its_name_should_be_its_original_name_dot_replace();
    test_should_not_create_replace_file_when_original_file_doesnt_exist();
}
