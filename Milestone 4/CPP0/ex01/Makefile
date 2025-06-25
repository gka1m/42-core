NAME = phonebook

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC		= Contact.cpp main.cpp PhoneBook.cpp
		  
OBJ		= $(SRC:.cpp=.o)

INCLUDES = PhoneBook.hpp Contact.hpp

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

all: $(NAME)

.PHONY: clean fclean re all