#include <Utils.hpp>
#include <asserts.hpp>

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

void RUN_UTILS_SUITE()
{
    test_should_replace_hello_world_by_ola_mundo();
    test_should_not_do_nothing_when_search_word_is_present_in_the_string();
}
