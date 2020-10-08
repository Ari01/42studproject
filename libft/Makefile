# VAR


NAME			= libft.a
TEST			= test
LIB				= ar cr

LIBDIR			= .
BIN				= bin

SRCS			= $(wildcard *.c)
OBJS			= $(SRCS:.c=.o)
LIBNAME			= ft

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LFLAGS			= -L $(LIBDIR) -l $(LIBNAME)
RM				= rm -f


# RULES 


all :			$(NAME)

$(NAME) :		$(OBJS)
				$(LIB) $@ $^

.c.o :
				$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $(<:.c=.o)

$(TEST) :		$(OBJS)
				$(CC) -o $@ $^

clean :
				$(RM) $(OBJS)

fclean :		clean
				$(RM) $(NAME) $(TEST)

re :			fclean all

.PHONY :		all clean fclean re test
