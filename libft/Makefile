# VAR


NAME			= libft.a
TEST			= test
LIB				= ar cr

SRCS			= $(wildcard *.c)
OBJS			= $(SRCS:.c=.o)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f


# RULES 


all :			$(NAME)

$(NAME) :		$(OBJS)
				$(LIB) $@ $^

.c.o :
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(TEST) :		$(OBJS)
				$(CC) -o $@ $^

clean :
				$(RM) $(OBJS)

fclean :		clean
				$(RM) $(NAME) $(TEST)

re :			fclean all

.PHONY :		all clean fclean re test
