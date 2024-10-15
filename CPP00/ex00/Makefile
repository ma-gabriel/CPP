
SRCS = megaphone.cpp

OBJECTS = $(SRCS:.cpp=.opp)

NAME = megaphone

CXX = c++

CPPFLAGS = -Wall -Wextra -Werror

%.opp: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ -I.

all: $(NAME)

$(NAME): $(OBJECTS) Makefile
	$(CXX) $(OBJECTS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: re all clean fclean
