
SRCS = main.cpp \
	   Harl.cpp

OBJECTS = $(SRCS:.cpp=.o)

NAME = harlFilter

CXX = c++

HEADERS =  Harl.hpp

CFLAGS = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp Makefile $(HEADERS)
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
