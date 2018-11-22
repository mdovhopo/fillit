/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tetr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:16:43 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/16 15:17:29 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TETR_H
# define T_TETR_H

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

typedef struct		s_tetr
{
	char			**matrix;
	int				offset;
	t_point			size;
	t_point			location;
	char			c;
	struct s_tetr	*next;
	struct s_tetr	*prev;
}					t_tetr;

#endif
