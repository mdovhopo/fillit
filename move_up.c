/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_corner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:57:28 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/16 17:08:52 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** move the tetrimino up to
** to the upper limit
*/

static void		move(char **matr)
{
	char	*tmp;
	int		k;

	tmp = matr[0];
	k = -1;
	while (++k < 3)
		matr[k] = matr[k + 1];
	matr[3] = tmp;
}

void			move_up(char **matr)
{
	int		i;
	int		j;
	int		line;

	i = 0;
	while (i < 4)
	{
		j = 0;
		line = 0;
		while (j < 4)
		{
			if (matr[i][j] == '.')
				line++;
			else
				return ;
			j++;
		}
		if (line == 4)
			move(matr);
		else
			i++;
	}
}
