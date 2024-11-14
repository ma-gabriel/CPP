
SRCS =	main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp

OBJECTS = $(SRCS:.cpp=.opp)

HEADERS = Weapon.hpp \
		  HumanA.hpp \
		  HumanB.hpp

NAME = weapon

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

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
