NAME = diamondtrap

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror

SRC		= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

INCLUDES = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
		  
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