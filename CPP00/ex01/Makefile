
SRCS =	main.cpp \
		PhoneBook.class.cpp \
		Contact.class.cpp

HEADERS =	PhoneBook.class.hpp \
			Contact.class.hpp

OBJECTS = $(SRCS:.cpp=.opp)

NAME = PhoneBook

CXX = c++

CPPFLAGS = -Wall -Wextra -Werror

%.opp: %.cpp $(HEADERS)
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
