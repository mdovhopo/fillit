/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:14:41 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/16 15:18:19 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_tetr.h"
#include <stdlib.h>

/*
** Set of functions, that deals with chained list
** of our tetriminos
*/

void		lst_del(t_tetr **tetr)
{
	t_tetr	*lst;
	t_tetr	*ptr;
	int		i;

	if (tetr && *tetr)
	{
		lst = *tetr;
		while (lst)
		{
			ptr = lst->next;
			i = 0;
			while (i < 4)
				free(lst->matrix[i++]);
			free(lst->matrix);
			free(lst);
			lst = NULL;
			lst = ptr;
		}
		*tetr = NULL;
	}
}

t_tetr		*lst_new(char **matrix, int offset, char c)
{
	t_tetr	*new_lst;

	new_lst = (t_tetr *)malloc(sizeof(t_tetr));
	if (new_lst)
	{
		new_lst->offset = offset;
		new_lst->matrix = matrix;
		new_lst->next = NULL;
		new_lst->prev = NULL;
		new_lst->size.x = 4;
		new_lst->size.y = 4;
		new_lst->location.x = 0;
		new_lst->location.y = 0;
		new_lst->c = c;
	}
	return (new_lst);
}

void		lst_add(t_tetr **tetr, t_tetr *new)
{
	if (new)
	{
		new->next = *tetr;
		if (new->next != NULL)
			new->next->prev = new;
		*tetr = new;
	}
}
