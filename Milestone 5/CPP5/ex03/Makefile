NAME = bureaucratform3

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC		= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

INCLUDES = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp
		  
OBJ		= $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f home_shrubbery

re: fclean $(NAME)

all: $(NAME)

.PHONY: clean fclean re all

# NAME = bureaucratform3

# CXX = c++
# CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
# INCLUDES = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp

# OBJ = $(SRC:.cpp=.o)
# DEP = $(SRC:.cpp=.d)  # dependency files

# # ---------------- Build executable ----------------
# $(NAME): $(OBJ)
# 	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

# # ---------------- Compile .cpp -> .o with .d ----------------
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# # ---------------- Include dependency files if they exist ----------------
# -include $(DEP)

# # ---------------- Clean ----------------
# clean:
# 	rm -f $(OBJ) $(DEP)

# fclean: clean
# 	rm -f $(NAME)
# 	rm -f home_shrubbery

# re: fclean all

# all: $(NAME)

# .PHONY: clean fclean re all
