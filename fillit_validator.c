/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:45:02 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/11 16:49:37 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** validator for given file:
** read by 21 characters from file
**
** valid_form - check if read piace of file have:
** # - 4
** . - 12
** \n - 5
** find_connect - find connections in tetrimino -
** it should be 6 of 8, otherwise - it is not a tetrimino
** velocycle - without velocycles no one program won't be the program :)
*/

static int			find_connect(char **matr, int i, int j, char c)
{
	int		count;

	count = 0;
	if (i + 1 < 4 && matr[i + 1][j] == c)
		count++;
	if (i - 1 > -1 && matr[i - 1][j] == c)
		count++;
	if (j - 1 > -1 && matr[i][j - 1] == c)
		count++;
	if (j + 1 < 4 && matr[i][j + 1] == c)
		count++;
	return (count);
}

static t_bool		is_tetr(char **matr, char c)
{
	int		i;
	int		j;
	int		connect;

	i = 0;
	connect = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (matr[i][j] == c)
				connect += find_connect(matr, i, j, c);
			j++;
		}
		i++;
	}
	if (connect == 6 || connect == 8)
		return (TRUE);
	return (FALSE);
}

static t_bool		valid_form(char *s)
{
	int		i;
	int		count_dots;
	int		count_sharps;
	int		count_endl;

	i = -1;
	count_dots = 0;
	count_sharps = 0;
	count_endl = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == '.')
			count_dots++;
		else if (s[i] == '#')
			count_sharps++;
		else if (s[i] == '\n' && GEN_POS(i))
			count_endl++;
		else
			return (FALSE);
	}
	if (i == 20 && s[i] == '\0')
		count_endl++;
	if (count_sharps == 4 && count_dots == 12 && count_endl == 5)
		return (TRUE);
	return (FALSE);
}

static int			velocycle(int fd, t_tetr **tetr, char *buff)
{
	char	c;
	char	**matr;
	int		ret;
	int		prev_ret;

	c = 'A';
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!valid_form(buff))
			return (-1);
		else if (c < 91 && is_tetr((matr = get_matrix(buff, c)), c))
		{
			move_up(matr, c);
			lst_add(&*tetr, lst_new(matr, get_offset(matr), c));
			c++;
		}
		else
		{
			lst_del(&*tetr);
			return (-1);
		}
		prev_ret = ret;
	}
	return (prev_ret);
}

t_tetr				*fillit_validator(char **argv)
{
	t_tetr	*tetr;
	int		fd;
	char	buff[BUFF_SIZE + 1];
	int		prev_ret;

	tetr = NULL;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (NULL);
	prev_ret = velocycle(fd, &tetr, buff);
	if (prev_ret < 0)
		return (NULL);
	if (prev_ret == 21)
		return (NULL);
	return (tetr);
}
