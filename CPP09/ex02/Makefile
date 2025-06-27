
SRCS =	main.cpp \
		PmergeMe.cpp

HEADERS = PmergeMe.hpp

OBJECTS = $(SRCS:.cpp=.o)

NAME = PmergeMe

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98


%.o: %.cpp Makefile $(HEADERS)
	$(CXX) $(CFLAGS) -c $< -o $@ -I.

all: $(NAME)

debug:
	$(MAKE) CFLAGS="$(CFLAGS) -DDEBUG"

$(NAME): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: re all clean fclean
