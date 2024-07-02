NAME=executable
COMPILER=c++
INCLUDES=-I includes/
FILES:=Utils.cpp
FILES:=$(addprefix src/, $(FILES))
TEST_FILES:=tests.cpp unit/Utils.cpp asserts.cpp
TEST_FILES:=$(addprefix tests/, $(TEST_FILES))

all: $(NAME)

$(NAME): $(FILES) src/main.cpp
	@$(COMPILER) $(INCLUDES) $(FILES) src/main.cpp -o $(NAME)
	@./$(NAME)

e2e: $(NAME)
	@./tests/e2e/Program.sh $(realpath $(NAME))

unit: $(FILES) $(TEST_FILES)
	@$(COMPILER) $(INCLUDES) $(FILES) $(TEST_FILES) -o unit
	@valgrind --leak-check=full -q ./unit
	@rm -rf unit
