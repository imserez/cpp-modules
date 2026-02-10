NAME	:= ex04
SRCS	:= main.cpp
OBJS	:= $(SRCS:.cpp=.o)
DEPS	:= $(OBJS:.o=.d)

CC		:= c++
CFLAGS	:= -Wall -Werror -Wextra -std=c++98 -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

-include $(DEPS)

%.o : %.cpp Makefile
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
