/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/03/12 23:21:38 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "cub3d.h"

void			ft_exit_esc(t_params *prm)
{
	mlx_destroy_image(prm->vars.mlx, prm->screen.obj);
	mlx_destroy_image(prm->vars.mlx, prm->dt_pics.so.obj);
	mlx_destroy_image(prm->vars.mlx, prm->dt_pics.ea.obj);
	mlx_destroy_image(prm->vars.mlx, prm->dt_pics.s.obj);
	mlx_destroy_image(prm->vars.mlx, prm->dt_pics.we.obj);
	mlx_destroy_image(prm->vars.mlx, prm->dt_pics.no.obj);
	free(prm->vars.mlx);
	free(prm->p_pics.ea);
	free(prm->p_pics.so);
	free(prm->p_pics.s);
	free(prm->p_pics.we);
	free(prm->p_pics.no);
	ft_protect(prm->map.self, prm->map.r);
	free(prm);
	ft_exit(0, prm);
}

void			ft_ws(int key, t_params *prm, double speed)
{
	if (key == 13)
	{
		if (prm->map.self[(int)(prm->player.r + speed
		* sin(prm->player.dir))][(int)(prm->player.c + speed
		* cos(prm->player.dir))] == '0')
		{
			prm->player.c += speed * cos(prm->player.dir);
			prm->player.r += speed * sin(prm->player.dir);
		}
	}
	if (key == 1)
	{
		if (prm->map.self[(int)(prm->player.r - speed
		* sin(prm->player.dir))][(int)(prm->player.c - speed
		* cos(prm->player.dir))] == '0')
		{
			prm->player.c -= speed * cos(prm->player.dir);
			prm->player.r -= speed * sin(prm->player.dir);
		}
	}
}

void			ft_ad(int key, t_params *prm, double speed)
{
	if (key == 0)
	{
		if (prm->map.self[(int)(prm->player.r - speed
		* cos(prm->player.dir))][(int)(prm->player.c +
		speed * sin(prm->player.dir))] == '0')
		{
			prm->player.c += speed * sin(prm->player.dir);
			prm->player.r -= speed * cos(prm->player.dir);
		}
	}
	if (key == 2)
	{
		if (prm->map.self[(int)(prm->player.r + speed
		* cos(prm->player.dir))][(int)(prm->player.c -
				speed * sin(prm->player.dir))] == '0')
		{
			prm->player.c -= speed * sin(prm->player.dir);
			prm->player.r += speed * cos(prm->player.dir);
		}
	}
}

void			ft_left_right(int key, t_params *prm, double r_speed)
{
	if (key == 123)
	{
		prm->player.dir = prm->player.dir - r_speed;
		if (prm->player.dir < 0)
			prm->player.dir = prm->player.dir + 2 * M_PI;
	}
	else if (key == 124)
	{
		prm->player.dir = prm->player.dir + r_speed;
		if (prm->player.dir >= 2 * M_PI)
			prm->player.dir = prm->player.dir - 2 * M_PI;
	}
}

int				ft_action(int key, t_params *prm)
{
	double speed;
	double r_speed;

	speed = 0.06;
	r_speed = 0.06;
	if (key == 13 || key == 1)
		ft_ws(key, prm, speed);
	if (key == 0 || key == 2)
		ft_ad(key, prm, speed);
	if (key == 124 || key == 123)
		ft_left_right(key, prm, r_speed);
	if (key == 53)
	{
		mlx_destroy_window(prm->vars.mlx, prm->vars.win);
		ft_exit_esc(prm);
	}
	render_next_frame(prm);
	return (0);
}
