.PHONY: all clean install uninstall

FLAGS = -Wall -Wextra -Werror #-I./libft/includes/ -I./includes/#-L./libft/ -lft

FILES = convert.c \
      ft_printf.c \
      read_flags.c \
      print_xob.c \
      print_di.c \
      print_tyr.c \
      print_u.c \
      print_s.c \
      print_c.c \
      print_fff.c \
      infin_mult.c \
      print_ff.c \
      handle_decoded.c \
      print_f.c

LIBFT_FILES = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_itoa_base.c \
		ft_uitoa_base.c \
		ft_abs.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strjoinfree.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putchars.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_strlcpy.c \
		ft_isspace.c

LIBFT_OBJ = $(addprefix ./libft/, $(LIBFT_FILES:%.c=%.o))

SRC_PATH = ./src/

SRC = $(addprefix $(SRC_PATH), $(FILES))

LIBFT = ./libft/libft.a

INCL = -I./includes -I./libft/includes

LIBFT_INCL = -Iincludes -Ilibft/includes

NAME = libftprintf.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_OBJ) $(OBJ)
	ar rc $(NAME) $(OBJ) $(LIBFT_OBJ)
	ranlib $(NAME)

$(LIBFT_OBJ): %.o: %.c
	gcc -c $(FLAGS) $(LIBFT_INCL) $< -o $@

$(OBJ): %.o: %.c
	gcc -c $(FLAGS) $(INCL) $< -o $@

clean:
	rm -f $(OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
