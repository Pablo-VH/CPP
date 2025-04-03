NAME = BraiiiiiiinnnzzzZ

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 $(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean: 
	rm -rf $(OBJS)

fclean: clean 
	rm -rf $(NAME)

re: fclean all

.PHONY: re all fclean clean