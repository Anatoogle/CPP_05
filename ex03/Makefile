NAME      = intern

CXX       = c++
CPPFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC_DIR	  = src
SRC       = $(SRC_DIR)/main.cpp \
			$(SRC_DIR)/AForm.cpp \
			$(SRC_DIR)/Bureaucrat.cpp \
			$(SRC_DIR)/ShrubberyCreationForm.cpp \
			$(SRC_DIR)/RobotomyRequestForm.cpp \
			$(SRC_DIR)/PresidentialPardonForm.cpp \
			$(SRC_DIR)/Intern.cpp

OBJ_DIR   = obj
OBJ       = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)


# Default rule
all: $(NAME)


# Link step
$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJ)


# Ensure obj/ exists before compiling each .cpp
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@


# Create obj/ folder if missing (get deleted at clean)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


# Cleaning rules
clean:
	rm -f $(OBJ_DIR)/*.o


fclean: clean
	rm -f $(NAME)


re: fclean all


.PHONY: all clean fclean re