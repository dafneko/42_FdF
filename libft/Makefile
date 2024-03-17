NAME = libft.a
HEADERDIR = .
CCFLAGS = -Wall -Werror -Wextra

SRC := ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		ft_isdigit.c ft_isprint.c ft_memset.c ft_strlcpy.c ft_strlen.c\
		ft_tolower.c ft_toupper.c ft_strncmp.c ft_memcmp.c ft_memcpy.c\
		ft_strchr.c ft_strrchr.c ft_memchr.c ft_strnstr.c ft_memmove.c\
		ft_strlcat.c ft_calloc.c ft_substr.c ft_strdup.c ft_strtrim.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_strmapi.c\
		ft_putnbr_fd.c\
		ft_putendl_fd.c\
		ft_striteri.c\
		ft_itoa.c\
		ft_strjoin.c\
		ft_split.c\
		ft_abs.c\
		ft_printf.c\
		printf_utils.c\
		get_next_line.c\
		ft_isspace.c\
		ft_atoi_base.c

OBJ := $(SRC:.c=.o)

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	cc -I $(HEADERDIR) $(CCFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY:
	all clean fclean re