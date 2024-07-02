#!/bin/bash

function ASSERT_STREQ()
{
if [[ "$1" == "$2" ]];
then
    printf ✅
else
    printf ❌
    echo -en "\nEXPECTED\n$1\n";
    echo -en "_______________________________________________\n";
    echo -en "RESULT\n$2";
fi
}

executable="valgrind --leak-check=full -q $1"

function test_should_replace_into_the_file_the_word_foo_with_bar()
{
    local file="test.txt"
    echo -n "foo" > $file
    local args="$file foo bar"
    local expected="bar"

    eval "$executable $args"
    local result=$(<$file)

    ASSERT_STREQ "$expected" "$result"

    rm -rf $file "$file.replace"
}

function test_should_replace_into_the_file_the_sentence_hello_world_with_ola_mundo()
{
    local file="test.txt"
    local args="$file 'hello world' 'ola mundo'"
    echo -n "Writing this sentence hello world to be replaced, hello world" > $file
    local expected="Writing this sentence ola mundo to be replaced, ola mundo"

    eval "$executable $args"
    local result=$(<$file)

    ASSERT_STREQ "$expected" "$result"

    rm -rf $file "$file.replace"
}

function test_should_receive_an_error_message_when_inputs_an_invalid_filename()
{
    local args="noexist.txt 'hello world' 'ola mundo'"
    local expected="Invalid filename."

    local result=$(eval "2>&1 $executable $args")

    ASSERT_STREQ "$expected" "$result"
}

function test_should_receive_an_error_message_when_pass_2_args_to_executable()
{
    local file="test.txt"
    echo -n "foo" > $file
    local args="$file 'hello world'"
    local expected="Invalid number of arguments."

    local result=$(eval "2>&1 $executable $args")

    ASSERT_STREQ "$expected" "$result"
    rm -rf $file "$file.replace"
}

test_should_replace_into_the_file_the_word_foo_with_bar
test_should_replace_into_the_file_the_sentence_hello_world_with_ola_mundo
test_should_receive_an_error_message_when_inputs_an_invalid_filename
test_should_receive_an_error_message_when_pass_2_args_to_executable
printf \\n
