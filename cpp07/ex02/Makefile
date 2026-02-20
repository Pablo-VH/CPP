NAME = array

CXX = c++
#CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 \
	#-fsanitize=address,undefined -fno-omit-frame-pointer -pedantic -Wshadow -g2 

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re