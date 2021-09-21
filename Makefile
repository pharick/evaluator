NAME		= evaluate

CC			= clang++
RM			= rm -f

SRCS		= main.cpp parse.cpp postfix.cpp evaluate.cpp utils.cpp \
              tokens/Number.cpp tokens/Operator.cpp \
              tokens/ParenthesisOpen.cpp tokens/ParenthesisClose.cpp
OBJS		= $(SRCS:.cpp=.o)
DEPS		= $(SRCS:.cpp=.d)

CFLAGS		= -Wall -Wextra -Werror -std=c++98

all:		$(NAME)

%.o : %.cpp
			$(CC) $(CFLAGS) -c $< -o $@

%.d: %.cpp
			@set -e; $(RM) $@; \
			$(CC) -M $(CPPFLAGS) $< > $@.$$$$; \
			sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
			$(RM) $@.$$$$

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS) $(DEPS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

include $(DEPS)

.PHONY: clean fclean re all test
