
SRCS =	main.cpp

OBJECTS = $(SRCS:.cpp=.opp)

HEADERS = 

NAME = hi

CXX = c++

CFLAGS = -Wall -Wextra -Werror

%.opp: %.cpp Makefile $(HEADERS)
	$(CXX) $(CFLAGS) -c $< -o $@ -I.

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: re all clean fclean
