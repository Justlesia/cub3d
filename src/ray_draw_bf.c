/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw_bf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/03/09 20:14:15 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "cub3d.h"

int						ft_basic_frame(t_params *prm, t_texture screen)
{
	int				width;
	int				length;
	unsigned long	c;
	unsigned long	f;

	c = prm->c.r << 16 | prm->c.g << 8 | prm->c.b;
	f = prm->f.r << 16 | prm->f.g << 8 | prm->f.b;
	width = 0;
	while (width < prm->r.x + 0)
	{
		length = 0;
		while (length < prm->r.y)
		{
			if (length < prm->r.y / 2)
				screen.data[screen.sizeline / 4 * length + width] = c;
			else
				screen.data[screen.sizeline / 4 * length + width] = f;
			length++;
		}
		width++;
	}
	return (0);
}
