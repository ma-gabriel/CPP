
SRCS = main.cpp \
	   Harl.cpp

OBJECTS = $(SRCS:.cpp=.o)

NAME = ex05

CXX = c++


HEADERS =  Harl.hpp

CPPFLAGS = -Wall -Wextra -Werror

%.opp: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ -I.

all: $(NAME)

$(NAME): $(OBJECTS) Makefile $(HEADERS)
	$(CXX) $(OBJECTS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: re all clean fclean
