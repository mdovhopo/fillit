/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:51:27 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/11/21 19:05:50 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_fillmatrix(size_t size, unsigned char c)
{
	char			**arr;
	size_t			i;
	size_t			j;

	j = -1;
	i = -1;
	arr = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	while (++i < size)
		arr[i] = (char *)ft_memalloc(sizeof(char) * (size + 1));
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			arr[i][j] = c;
	}
	arr[i] = NULL;
	return (arr);
}
