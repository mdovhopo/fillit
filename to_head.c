/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:41:10 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/16 16:41:21 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_tetr.h"
#include <stdlib.h>

static void		sizeoftetr(t_tetr *head)
{
	int		i;
	int		j;
	int		k;
	int		y;

	i = -1;
	y = 0;
	while (++i < 4)
	{
		k = 0;
		j = 4;
		while (--j > -1 + head->offset)
		{
			if (head->matrix[i][j] == '.')
				k++;
			else if (head->matrix[i][j] != '.')
				break ;
		}
		if (k == 4 - head->offset)
			y++;
		else if (head->size.x > k)
			head->size.x = k;
	}
	head->size.y = 4 - y;
	head->size.x = 4 - head->offset - head->size.x;
}

t_tetr			*to_head(t_tetr *tetr, int *size)
{
	int		len;

	len = 0;
	while (tetr)
	{
		len++;
		sizeoftetr(tetr);
		tetr->location.x = 0;
		tetr->location.y = 0;
		if (tetr->next == NULL)
		{
			if (size != NULL)
				*size = len;
			return (tetr);
		}
		tetr = tetr->next;
	}
	return (NULL);
}
