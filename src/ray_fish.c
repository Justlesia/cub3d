/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_fish.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/03/12 23:27:08 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "cub3d.h"

t_dir_info				ft_i_init(t_params *prm)
{
	t_dir_info			i;

	i.angle = 67 * M_PI / 180;
	i.dir = prm->player.dir - i.angle / 2;
	i.dir_end = prm->player.dir + i.angle / 2;
	i.w_angle = i.angle / prm->r.x;
	return (i);
}

t_dir_info				ft_while_not_a_wall(t_plr player, char **map,
								t_dir_info i)
{
	i.spr = 0;
	i.wall_x = player.c;
	i.wall_y = player.r;
	i.c_dir = cos(i.dir) / 300;
	i.s_dir = sin(i.dir) / 300;
	while (map[(int)(i.wall_y)][(int)(i.wall_x)] != '1')
	{
		if (map[(int)(i.wall_y)][(int)(i.wall_x)] == '2' && i.spr < 499)
		{
			if ((int)(i.wall_y) != (int)(i.s_wall_y[i.spr]) ||
				(int)(i.wall_x) != (int)(i.s_wall_x[i.spr]))
			{
				i.spr = i.spr + 1;
				i.s_wall_x[i.spr] = i.wall_x;
				i.s_wall_y[i.spr] = i.wall_y;
			}
		}
		i.wall_x += i.c_dir;
		i.wall_y += i.s_dir;
	}
	return (i);
}

int						ft_walls(t_params *prm)
{
	t_pic_and_x			pic_x;
	t_dir_info			i;
	int					line_height;
	int					x;

	i = ft_i_init(prm);
	x = 0;
	while (i.dir <= i.dir_end)
	{
		i = ft_while_not_a_wall(prm->player, prm->map.self, i);
		line_height = nearbyint((prm->r.y / distance(i.wall_x, i.wall_y,
				prm->player.c, prm->player.r)) /
				log(prm->r.x - llabs(x - prm->r.x / 2)) * 3.2);
		pic_x = ft_what_pic_and_local_x(prm, i.wall_x, i.wall_y, line_height);
		draw_wall_line(prm, line_height, pic_x, x);
		while ((i.spr) > 0)
		{
			draw_sprite_line(prm, i.s_wall_x[i.spr], i.s_wall_y[i.spr], x);
			i.spr--;
		}
		x++;
		i.dir += i.w_angle;
	}
	return (0);
}
