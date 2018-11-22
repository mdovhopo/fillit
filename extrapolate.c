/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrapolate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:15:36 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/19 19:15:37 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** finde the next value after
** 4(amout blocks for tetrimino) * x(amount of tetriminos)
** that have square root
*/

int		extrapolate(int x)
{
	int	sq;

	sq = 2;
	if (x == 2)
		return (3);
	else if (x == 1)
		return (2);
	x *= 4;
	while (1)
	{
		if (x > sq * sq)
			sq++;
		else
			break ;
	}
	return (sq - 1);
}
