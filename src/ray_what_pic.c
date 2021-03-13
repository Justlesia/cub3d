/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_what_pic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/03/10 13:20:34 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "cub3d.h"

t_pic_and_x				ft_what_pic_and_local_x_end(t_params *prm,
						t_pic_and_x pic_x, t_dist d)
{
	if ((int)(d.nw * 1000) == 999 && (int)(d.se * 1000) == 998)
		pic_x.pic = prm->dt_pics.no;
	if ((int)(d.sw * 1000) == 999 && (int)(d.ne * 1000) == 998)
		pic_x.pic = prm->dt_pics.so;
	if ((int)(d.nw * 1000) == 998 && (int)(d.se * 1000) == 999)
		pic_x.pic = prm->dt_pics.ea;
	if ((int)(d.sw * 1000) == 998 && (int)(d.ne * 1000) == 999)
		pic_x.pic = prm->dt_pics.we;
	return (pic_x);
}

t_dist					ft_count_dist(double w_x, double w_y)
{
	t_dist				d;

	d.nw = distance(w_x, w_y, floor(w_x), floor(w_y));
	d.sw = distance(w_x, w_y, floor(w_x), ceil(w_y));
	d.se = distance(w_x, w_y, ceil(w_x), ceil(w_y));
	d.ne = distance(w_x, w_y, ceil(w_x), floor(w_y));
	return (d);
}

t_pic_and_x				ft_what_pic_and_local_x_else(t_params *prm,
						t_dist d, int line_height)
{
	t_pic_and_x			pic_x;

	pic_x.pic = prm->dt_pics.ea;
	pic_x.local_x = d.se / (d.se + d.ne) * line_height;
	return (pic_x);
}

t_pic_and_x				ft_what_pic_and_local_x(t_params *prm, double w_x,
						double w_y, int line_height)
{
	t_dist				d;
	t_pic_and_x			pic_x;

	d = ft_count_dist(w_x, w_y);
	if ((d.nw + d.sw) < (d.sw + d.se) && (d.nw + d.sw)
		< (d.ne + d.se) && (d.nw + d.sw) < (d.nw + d.ne))
	{
		pic_x.pic = prm->dt_pics.we;
		pic_x.local_x = d.nw / (d.nw + d.sw) * line_height;
	}
	else if ((d.sw + d.se) <= (d.nw + d.sw) && (d.sw + d.se)
		<= (d.ne + d.se) && (d.sw + d.se) <= (d.nw + d.ne))
	{
		pic_x.pic = prm->dt_pics.so;
		pic_x.local_x = d.sw / (d.sw + d.se) * line_height;
	}
	else if ((d.nw + d.ne) <= (d.nw + d.sw) && (d.nw + d.ne)
		<= (d.ne + d.se) && (d.nw + d.ne) <= (d.sw + d.se))
	{
		pic_x.pic = prm->dt_pics.no;
		pic_x.local_x = d.ne / (d.ne + d.nw) * line_height;
	}
	else
		pic_x = ft_what_pic_and_local_x_else(prm, d, line_height);
	return (ft_what_pic_and_local_x_end(prm, pic_x, d));
}
