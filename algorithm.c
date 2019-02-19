/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:39:14 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/21 18:39:15 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** main algorithm, that are implementing an idea of backtraking
** magic - recursive func, that go deeper into recursion
** if we can paste tetrimino in current position, and go ahead if no
** if it is no solution, the algorithm returns to previos
** tetrimino. if it is no tetrimino left func returns and
** increments matrix for solution by 1
*/

static void			fill(t_tetr *head, char **tab, char c)
{
	int		x;
	int		y;
	int		k;

	k = head->location.x;
	y = 0;
	while (y < head->size.y)
	{
		x = 0;
		while (x < head->size.x)
		{
			if (head->matrix[y][x + head->offset] == head->c)
				tab[y + head->location.y][x + head->location.x] = c;
			x++;
		}
		y++;
	}
}

static short int	check_tetr(t_tetr *head, char **tab)
{
	int		x;
	int		y;

	y = 0;
	while (y < head->size.y)
	{
		x = 0;
		while (x < head->size.x)
		{
			if (head->matrix[y][x + head->offset] == head->c)
				if (tab[y + head->location.y][x + head->location.x] != '.')
					return (OVERLAP);
			x++;
		}
		y++;
	}
	return (OK);
}

static t_bool		magic(int size, char **result, t_tetr *head)
{
	if (head == NULL)
		return (TRUE);
	head->location.y = 0;
	while (head->location.y < size - head->size.y + 1)
	{
		head->location.x = 0;
		while (head->location.x < size - head->size.x + 1)
		{
			if (check_tetr(head, result) == OK)
			{
				fill(head, result, head->c);
				if (magic(size, result, head->prev) == FALSE)
					fill(head, result, '.');
				else
					return (TRUE);
			}
			head->location.x++;
		}
		head->location.y++;
	}
	return (FALSE);
}

char				**algorithm(int *size, t_tetr *head)
{
	char	**result;

	result = ft_fillmatrix(*size, '.');
	while ((magic(*size, result, head)) == FALSE)
	{
		delmatrix(result, *size);
		result = ft_fillmatrix(*size += 1, '.');
		head = to_head(head, NULL);
	}
	return (result);
}
