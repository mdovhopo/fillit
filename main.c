/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:58:35 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/22 17:49:00 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** calls func head cause tetriminos in list
** placed from Z to A and i need to move my
** list to A
*/

static void		print_result(int size, char **result)
{
	int i;

	i = -1;
	while (++i < size)
	{
		write(1, result[i], size);
		write(1, "\n", 1);
	}
}

int				main(int argc, char const **argv)
{
	t_tetr	*tetr;
	t_tetr	*head;
	int		size;
	char	**result;

	size = 0;
	if (argc != 2)
	{
		write(1, USAGE, 20);
		return (0);
	}
	if ((tetr = fillit_validator((char **)argv)) == NULL)
	{
		write(1, ERROR, 6);
		return (0);
	}
	head = to_head(tetr, &size);
	size = extrapolate(size);
	result = algorithm(&size, head);
	print_result(size, result);
	return (0);
}
