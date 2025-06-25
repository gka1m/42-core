NAME = account

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC		= tests.cpp Account.cpp
		  
OBJ		= $(SRC:.cpp=.o)

INCLUDES = Account.hpp

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