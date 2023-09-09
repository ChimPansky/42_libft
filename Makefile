NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

HEADER = libft.h
SRC = \
	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_isspace.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memrchr.c \
	ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
	ft_tolower.c ft_toupper.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) $(HEADER)
	ar -rcs $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)
	

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re test so