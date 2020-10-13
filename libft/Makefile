# VAR


NAME			= libft.a
LIB				= ar cr
TEST			= test

SRCS			= $(wildcard *.c)
FILES			= $(wildcard *fic)
OBJS			= $(SRCS:.c=.o)

INCLDDIR		= .
TESTSDIR		= resources/tests/
TESTS			= asciitest memtest stringtest advancedstringtest

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
INCLDFLAGS		= -I $(INCLDDIR)
RM				= rm -f


# RULES 


all :				$(NAME)

$(NAME) :			$(OBJS)
					$(LIB) $@ $^

$(TEST) :			$(TESTS)

$(TESTS) :			%: $(TESTSDIR)%.c $(OBJS)
					$(CC) $(CFLAGS) $(INCLDFLAGS) -o $@ $^

.c.o :
					$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
					$(RM) $(OBJS)

fclean :			clean
					$(RM) $(NAME) $(TESTS) $(FILES)

re :				clean fclean all

.PHONY :			all clean fclean re test
