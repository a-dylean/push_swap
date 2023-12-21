# compiler and flags
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror

# name of the target program
NAME	=	libft.a

# commands
RM	=	rm -f
AR	=	ar -rcs

# special include directories
INCLUDE	=	libft.h

# other source files and the associated object files
SOURCES	=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_tolower.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcpy.c \
			ft_memcmp.c ft_memset.c ft_strchr.c ft_strlcat.c ft_toupper.c \
			ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_calloc.c ft_strrchr.c \
			ft_memmove.c ft_strdup.c ft_strnstr.c ft_strjoin.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c \
			ft_strtrim.c ft_substr.c ft_split.c ft_itoa.c ft_striteri.c

OBJECTS	=	$(SOURCES:.c=.o)

# default 'make'
all:	$(NAME)

$(NAME):	$(OBJECTS) $(INCLUDE)
			$(AR) $(NAME) $(OBJECTS)

# specifying how to compile the .c files
.c.o:	$(CC) (CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

# remove .o files
clean:
		$(RM) $(OBJECTS)

# remove .o files and binaries
fclean:	clean
		$(RM) $(NAME)

# remove files and re-make
re:	fclean all

#  to avoid relinking
.PHONY:	all clean fclean re