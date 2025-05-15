########## COLORS ##########
GREEN := \033[32m
RED := \033[31m
BLUE := \033[34m
YELLOW := \033[33m
RESET := \033[0m
BOLD := \033[1m

########## FLAGS ##########
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -Wshadow \
		-fsanitize=address,leak,undefined \
		-fno-omit-frame-pointer -g3 -O1
INCLUDES := -Iincludes

########## FILES ##########
SRC_DIR := srcs
OBJ_DIR := objs
SRC_FILES := $(SRC_DIR)/AMateria.cpp \
			$(SRC_DIR)/Character.cpp \
			$(SRC_DIR)/Cure.cpp \
			$(SRC_DIR)/Ice.cpp \
			$(SRC_DIR)/MateriaSource.cpp \
			$(SRC_DIR)/main.cpp \
			$(SRC_DIR)/AMateria.cpp \
			$(SRC_DIR)/MateriaSource.cpp \
			$(SRC_DIR)/Character.cpp

OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
NAME := Materias

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

re: fclean all

.PHONY: all clean fclean re
