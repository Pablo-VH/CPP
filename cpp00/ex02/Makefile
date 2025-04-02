Name = dream_job

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp  tests.cpp\

OBJS = $(SRCS:.cpp=.o)

all: $(Name)

$(Name): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(Name) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(Name)

re: fclean all

.PHONY: all clean fclean re