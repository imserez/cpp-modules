NAME		:= ex02
SRCS		:= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp
OBJS		:= $(SRCS:.cpp=.o)
DEPS		:= $(OBJS:.o=.d)

CXX			:= c++
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

.PHONY: all re clean fclean
