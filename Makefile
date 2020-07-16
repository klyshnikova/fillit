# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 16:40:34 by jemendy           #+#    #+#              #
#    Updated: 2019/08/06 16:03:20 by jemendy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB_DIR = libft

SRC = main.c ft_call_all_and_read_and_check.c ft_check_figure.c \
	ft_create_list_and_record_coordinate.c ft_clean.c \
 	ft_malloc_map.c ft_result.c

OBJ = $(SRC:.c=.o)

LIBA = libft.a

R_LIBA = @make -C $(LIB_DIR)

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -L $(LIB_DIR) -lft

all: $(NAME)

$(OBJ): %.o: %.c
			@gcc -c $(CFLAGS) -I. $<

$(LIBA):
			$(R_LIBA)

$(NAME): $(LIBA) $(OBJ)
			@gcc $(CFLAGS) $(LFLAGS) -I. -o $@ $(OBJ)

clean:
			@rm -f $(OBJ)
			@make -C libft clean

fclean: clean
			@rm -f $(NAME)
			@make -C libft fclean

re: fclean all
