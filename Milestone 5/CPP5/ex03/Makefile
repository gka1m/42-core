NAME = bureaucratform

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC		= main.cpp Bureaucrat.cpp AForm.cpp \
		  ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
		  PresidentialPardonForm.cpp Intern.cpp

INCLUDES = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp \
		   RobotomyRequestForm.hpp PresidentialPardonForm.hpp \
		   Intern.hpp 
		  
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