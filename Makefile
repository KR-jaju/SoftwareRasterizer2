CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = software_rasterizer

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I./math -I./graphics

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all