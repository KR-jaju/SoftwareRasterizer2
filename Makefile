CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11 -g -I/Users/jaju/.brew/opt/sdl2/include 
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = software_rasterizer

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I./include

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) -L /Users/jaju/.brew/opt/sdl2/lib -lSDL2

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all