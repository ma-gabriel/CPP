
SRCS =	main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		forms/ShrubberyCreationForm.cpp \
		forms/RobotomyRequestForm.cpp \
		forms/PresidentialPardonForm.cpp

OBJECTS = $(SRCS:.cpp=.o)

HEADERS =	Bureaucrat.hpp \
			AForm.hpp\
			forms/ShrubberyCreationForm.hpp \
			forms/RobotomyRequestForm.hpp \
			forms/PresidentialPardonForm.hpp

NAME = ex02

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp Makefile $(HEADERS)
	$(CXX) $(CFLAGS) -c $< -o $@ -I. -Iforms

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
