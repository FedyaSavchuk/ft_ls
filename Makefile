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
		free_data \
		ft_itoa_base \
		ft_ls \
		ft_strjoin_safe \
		ft_strndup \
		print_result \
		sort
NAME = ft_ls
SRC = $(addprefix $(SRC_PATH), $(addsuffix .c, $(FUNCS)))
OBJS = $(addsuffix .o, $(FUNCS))
SRC_PATH = ./
INCLUDE_PATH = ./
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_PATH)
LIBFT = Libft/lidft.a
LIBS = -L./Libft -lft
RED = "\033[1;31m"
PURPLE = "\033[1;35m"
GREEN = "\033[1;32m"
NOCOLOR = "\033[0m"

all: $(NAME)

compile:
	@echo $(PURPLE)">>> Compiling..."$(NOCOLOR)

$(LIBFT):
	make -C ./libft

$(OBJS): %.o: $(SRC_PATH)%.c
	gcc -c $(CFLAGS) $^

$(NAME): compile $(LIBFT) $(OBJS)
	gcc $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)
	@echo $(GREEN)">>> Succes!"$(NOCOLOR)
clean:
	@echo $(PURPLE)">>> Deleting object files.."$(NOCOLOR)
	rm -f $(OBJS)
	make -C ./libft clean
fclean: clean
	@echo $(PURPLE)">>> Deleting fillit..."$(NOCOLOR)
	rm -f ./libft/$(LIBFT)
	rm -f $(NAME)
	@echo $(GREEN)">>> fillit deleted"$(NOCOLOR)'\n'
re: fclean all
