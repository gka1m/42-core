NAME = fixed3

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC		= main.cpp Fixed.cpp

INCLUDES = Fixed.hpp
		  
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