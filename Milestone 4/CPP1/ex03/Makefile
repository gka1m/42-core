NAME = attack

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC		= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

INCLUDES = HumanA.hpp HumanB.hpp Weapon.hpp
		  
OBJ		= $(SRC:.cpp=.o)

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