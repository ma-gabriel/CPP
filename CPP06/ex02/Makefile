
SRCS =	main.cpp \
		utils.cpp \
		Base.cpp \
		ABC/A.cpp \
		ABC/B.cpp \
		ABC/C.cpp

OBJECTS = $(SRCS:.cpp=.o)

HEADERS =	utils.hpp \
			Base.hpp \
			ABC/A.hpp \
			ABC/B.hpp \
			ABC/C.hpp

NAME = ex02

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp Makefile $(HEADERS)
	$(CXX) $(CFLAGS) -c $< -o $@ -I. -IABC

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
