/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:29:01 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/16 15:29:03 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_tetr.h"

/*
** Convert the line, read from valid file
*/

char	**get_matrix(char *s, char c)
{
	char	**matr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	matr = malloc(sizeof(char *) * 4);
	while (i < 4)
	{
		matr[i] = malloc(sizeof(char *) * 5);
		j = 0;
		while (j < 4)
		{
			if (*s == '#')
				*s = c;
			matr[i][j++] = *s++;
		}
		s++;
		matr[i][j] = '\0';
		i++;
	}
	return (matr);
}
