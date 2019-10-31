#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolen <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 15:10:57 by aolen             #+#    #+#              #
#    Updated: 2019/09/21 17:32:55 by lcarmelo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FUNCS = \
		complete_list \
		complete_list_2 \
		print_result \
		additional_funcs \
		ft_ls \
		ft_strjoin_safe \
		ft_strndup \
		sort \
		print_errors \
		sort_args \
		get_flags
NAME = ft_ls
SRC = $(addprefix $(SRC_PATH), $(addsuffix .c, $(FUNCS)))
OBJS = $(addsuffix .o, $(FUNCS))
SRC_PATH = ./
INCLUDE_PATH = ./
CFLAGS = -g -Wall -Wextra -Werror -I$(INCLUDE_PATH)
OPT = -ofast
LIBFT = ft_printf/libftprintf.a
LIBS = -L./ft_printf -lftprintf
RED = "\033[1;31m"
PURPLE = "\033[1;35m"
GREEN = "\033[1;32m"
NOCOLOR = "\033[0m"

all: $(NAME)

compile:
	@echo $(PURPLE)">>> Compiling..."$(NOCOLOR)

$(LIBFT):
	make -C ./ft_printf

$(OBJS): %.o: $(SRC_PATH)%.c
	gcc $(OPT) -c $(CFLAGS) $^ -o $@

$(NAME): $(LIBFT) $(OBJS)
	gcc $(OPT) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)
	@echo $(GREEN)">>>Sucess! ft_ls installed"$(NOCOLOR)'\n'

clean:
	@echo $(PURPLE)">>> Deleting object files.."$(NOCOLOR)
	rm -f $(OBJS)
	@make -C ./ft_printf clean

fclean: clean
	@echo $(PURPLE)">>> Deleting ft_ls..."$(NOCOLOR)
	rm -f $(LIBFT)
	rm -f $(NAME)
	@echo $(GREEN)">>> ft_ls deleted"$(NOCOLOR)'\n'

re: fclean all
