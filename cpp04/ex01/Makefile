NAME	:= ex01
SRCS	:= main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS	:= $(SRCS:.cpp=.o)
DEPS	:= $(OBJS:.o=.d)

CXX		:= c++
CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98 -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

-include $(DEPS)

%.o : %.cpp Makefile
	$(CXX) $(CXXFLAGS) -MMD -c -o $@ $<

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
