
SRCS = megaphone.cpp

OBJECTS = $(SRCS:.cpp=.opp)

NAME = megaphone

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

%.opp: %.cpp Makefile
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
