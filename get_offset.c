/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_offset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:08:34 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/20 13:08:35 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** calculate the minimal distance
**	from left border to tetrimino
*/

int		get_offset(char **matr)
{
	int		i;
	int		j;
	int		offset;
	int		prev_off;

	offset = 3;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		prev_off = 0;
		while (++j < 4)
		{
			if (matr[i][j] != '.')
				break ;
			if (matr[i][j] == '.')
				prev_off++;
		}
		if (prev_off < offset)
			offset = prev_off;
		else if (prev_off == 4)
			return (offset);
	}
	return (offset);
}
