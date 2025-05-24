########## COLORS ##########
GREEN := \033[32m
RED := \033[31m
BLUE := \033[34m
YELLOW := \033[33m
RESET := \033[0m
BOLD := \033[1m

########## FLAGS ##########
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 \
		-MMD -MP -Wshadow \
		-fsanitize=address,leak,undefined \
		-fno-omit-frame-pointer -g3 -O1
INCLUDES := -Iincludes

########## FILES ##########
SRC_DIR := srcs
OBJ_DIR := objs
SRC_FILES := $(SRC_DIR)/main.cpp \
			$(SRC_DIR)/ScalarConverter.cpp \
			$(SRC_DIR)/convertPrinters.cpp \
			$(SRC_DIR)/convertUtils.cpp

OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
NAME := Convert

########## RULES ##########
all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@printf "$(GREEN)$(BOLD)[✓] $@ compiled successfully!$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(BLUE)Compiling $(BOLD)$<$(RESET)\n"

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)[x] Object files cleaned.$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)[x] Executable $(NAME) removed.$(RESET)\n"

test: $(NAME)
	@printf "$(YELLOW)$(BOLD)Running tests...$(RESET)\n"
	
	@printf "$(YELLOW)\ninput: 42$(RESET)\n"
	@./$(NAME) 42
	
	@printf "$(YELLOW)\ninput: 42.0$(RESET)\n"
	@./$(NAME) 42.0
	
	@printf "$(YELLOW)\ninput: 42.0f$(RESET)\n"
	@./$(NAME) '42.0f'
	
	@printf "$(YELLOW)\ninput: 42.f$(RESET)\n"
	@./$(NAME) '42.f'
	
	@printf "$(YELLOW)\ninput: .42$(RESET)\n"
	@./$(NAME) '.42'
	
	@printf "$(YELLOW)\ninput: 0.0$(RESET)\n"
	@./$(NAME) '0.0'

	@printf "$(YELLOW)\ninput: -3.222222222222222222$(RESET)\n"
	@./$(NAME) '-3.222222222222222222'

	@printf "$(YELLOW)\ninput: nan$(RESET)\n"
	@./$(NAME) 'nan'
	
	@printf "$(YELLOW)\ninput: +inf$(RESET)\n"
	@./$(NAME) '+inf'

	@printf "$(YELLOW)\ninput: -inff$(RESET)\n"
	@./$(NAME) '-inff'

	@printf "$(YELLOW)\ninput: w$(RESET)\n"
	@./$(NAME) 'w'

	@printf "$(YELLOW)\ninput: hello world$(RESET)\n"
	@./$(NAME) "hello world"

re: fclean all

.PHONY: all clean fclean test re

-include $(OBJ_FILES:.o=.d)
