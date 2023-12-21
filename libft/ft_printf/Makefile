CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libftprintf.a
INCLUDE	=	ft_printf.h
SOURCES	=	$(wildcard *.c)
OBJECTS	=	$(SOURCES:.c=.o)
RM	=	rm -f
AR	=	ar -rcs
all:	$(NAME)

$(NAME):	$(OBJECTS)
			$(AR) $(NAME) $(OBJECTS)

.o:.c	$(CC) $(CFLAGS) $(INCLUDE) -c $<

clean:
		$(RM) $(OBJECTS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re