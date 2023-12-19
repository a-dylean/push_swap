CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	push_swap
INCLUDE	=	push_swap.h
SOURCES	=	$(wildcard *.c)
OBJECTS	=	$(SOURCES:.c=.o)
RM	=	rm -f
AR	=	ar -rcs
all:	$(NAME)

$(NAME):	$(OBJECTS)
			$(AR) $(NAME) $(OBJECTS)

.c.o:   $(CC) (CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDE)

clean:
		$(RM) $(OBJECTS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re