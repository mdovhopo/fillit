# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 16:47:08 by mdovhopo          #+#    #+#              #
#    Updated: 2018/11/16 16:51:03 by mdovhopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

INCLUDES = fillit.h t_tetr.h

SRC_C = fillit_validator.c get_matrix.c get_offset.c list.c ft_memalloc.c delmatrix.c ft_fillmatrix.c main.c to_head.c move_up.c extrapolate.c algorithm.c

SRC_O = $(SRC_C:.c=.o)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(SRC_O)
	@gcc $(FLAGS) -o $(NAME) $(SRC_O)

clean:	
	@/bin/rm -f $(SRC_O)

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all

magic:
	clear
	@echo "*making magic*"
	@echo " 	.∧＿∧"
	@echo " 	( ･ω･｡)つ━☆・*。"
	@echo "	⊂　 ノ 　　　・゜+."
	@echo "	しーＪ　　　°。+ *´¨)"
	@echo "                 .· ´¸.·*´¨) ¸.·*¨)"
	@echo "　　　　　　　　(¸.·´ (¸.·'* ☆"
