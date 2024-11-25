
SRCS =	main.cpp \
		PhoneBook.cpp \
		Contact.cpp

HEADERS =	PhoneBook.hpp \
			Contact.hpp

OBJECTS = $(SRCS:.cpp=.o)

NAME = PhoneBook

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp $(HEADERS) Makefile
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
