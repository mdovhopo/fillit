/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:46:09 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/22 17:49:11 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "t_tetr.h"

# define ERROR "error\n"
# define USAGE "usage: ./fillit map\n"
# define BUFF_SIZE 21
# define GEN_POS(x) (x == 4 || x == 9 || x == 14 || x == 19 || x == 20)
# define SIZE_ERROR -1
# define OVERLAP 0
# define OK 1
# define TRUE 1
# define FALSE 0

typedef unsigned short int	t_bool;

t_tetr			*fillit_validator(char **argv);
void			lst_del(t_tetr **tetr);
t_tetr			*lst_new(char **matrix, int	offset, char c);
void			lst_add(t_tetr **tetr, t_tetr *new);
char			**get_matrix(char *s, char c);
void			move_up(char **matr, char c);
int				get_offset(char **matr);
t_tetr			*to_head(t_tetr *tetr, int *size);
int				extrapolate(int x);
char			**ft_fillmatrix(size_t size, unsigned char c);
void			*ft_memalloc(size_t size);
void			delmatrix(char **tab, int size);
char			**algorithm(int *size, t_tetr *head);

#endif
