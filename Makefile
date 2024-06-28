NAME=executable
COMPILER=c++
INCLUDES=-I includes/
FILES:=Utils.cpp
FILES:=$(addprefix src/, $(FILES))
TEST_FILES:=tests.cpp unit/Utils.cpp asserts.cpp
TEST_FILES:=$(addprefix tests/, $(TEST_FILES))

all: $(NAME)

$(NAME): main.cpp
	@$(COMPILER) -std=c++98 main.cpp -o $(NAME)
	@./$(NAME)

unit: $(FILES) $(TEST_FILES)
	@$(COMPILER) $(INCLUDES) -std=c++98 $(FILES) $(TEST_FILES) -o unit
	@valgrind --leak-check=full -q ./unit
	@rm -rf unit
