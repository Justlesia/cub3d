/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/03/09 19:39:39 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "cub3d.h"

int					ft_start(t_params *prm, int line_height)
{
	int start;

	start = (prm->r.y - line_height) / 2;
	return (start < 0 ? 0 : start);
}

int					ft_end(t_params *prm, int line_height)
{
	int end;

	end = (prm->r.y + line_height) / 2;
	return (end >= prm->r.y ? prm->r.y - 1 : end);
}

void				draw_wall_line(t_params *prm, int line_height,
									t_pic_and_x pic_x, int x)
{
	int start;
	int end;
	int color;
	int local_y;

	start = ft_start(prm, line_height);
	end = ft_end(prm, line_height);
	local_y = 0;
	while (start < end)
	{
		color = pic_x.pic.data[pic_x.pic.sizeline / (pic_x.pic.bpp / 8) *
				(int)(1.0 * local_y / line_height * pic_x.pic.img_height) +
				(int)(1.0 * pic_x.local_x / line_height * pic_x.pic.img_width)];
		prm->screen.data[prm->screen.sizeline / 4 * start + x] = color;
		start++;
		local_y++;
	}
}

int					ft_sprite_color(t_params *prm, int local_x,
									int local_y, t_line l_i)
{
	return (prm->dt_pics.s.data[prm->dt_pics.s.sizeline /
			(prm->dt_pics.s.bpp / 8) * (int)(1.0 * local_y /
			l_i.line_height * prm->dt_pics.s.img_height) +
			(int)(1.0 * local_x / l_i.line_height *
			prm->dt_pics.s.img_width)]);
}

void				draw_sprite_line(t_params *prm, double w_x,
											double w_y, int x)
{
	t_line			l_i;
	int				color;
	int				local_y;
	int				local_x;

	l_i.line_height = nearbyint((prm->r.y / distance(floor(w_x) + 0.50,
		floor(w_y) + 0.50, prm->player.c, prm->player.r)) /
			log(prm->r.x - llabs(x - prm->r.x / 2)) * 3.5);
	l_i.start = ft_start(prm, l_i.line_height);
	l_i.end = ft_end(prm, l_i.line_height);
	local_x = l_i.line_height * (0.5 + (distance(floor(w_x) + 0.50,
		floor(w_y) + 0.50, prm->player.c, prm->player.r) *
		tan(atan2(floor(w_x) + 0.50 - prm->player.c, floor(w_y) + 0.50 -
		prm->player.r) - atan2(w_x - prm->player.c, w_y - prm->player.r))));
	if (local_x < 0 || local_x > l_i.line_height)
		return ;
	local_y = 0;
	while (l_i.start < l_i.end)
	{
		color = ft_sprite_color(prm, local_x, local_y, l_i);
		if ((color != 0xffffff) && (color != 0))
			prm->screen.data[prm->screen.sizeline / 4 * l_i.start + x] = color;
		l_i.start++;
		local_y++;
	}
}
