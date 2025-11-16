NAME = Materia

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp MateriaSource.cpp Cure.cpp Ice.cpp Character.cpp AMateria.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re