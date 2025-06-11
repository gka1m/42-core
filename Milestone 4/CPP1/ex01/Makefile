NAME = zombieHorde

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror

SRC		= Zombie.cpp main.cpp zombieHorde.cpp
		  
OBJ		= $(SRC:.cpp=.o)

INCLUDES = Zombie.hpp

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