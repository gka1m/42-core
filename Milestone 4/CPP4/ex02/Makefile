NAME = animal

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror

SRC		= main.cpp Dog.cpp Cat.cpp Animal.cpp Brain.cpp

INCLUDES = Dog.hpp Cat.hpp Animal.hpp Brain.hpp
		  
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