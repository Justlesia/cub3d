/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/03/12 21:44:22 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "cub3d.h"

int						render_next_frame(t_params *prm)
{
	mlx_do_sync(prm->vars.mlx);
	ft_basic_frame(prm, prm->screen);
	ft_walls(prm);
	mlx_put_image_to_window(prm->vars.mlx, prm->vars.win,
							prm->screen.obj, 0, 0);
	return (0);
}

void					first_frame(t_params *prm)
{
	int				sizex;
	int				sizey;

	mlx_get_screen_size(prm->vars.mlx, &sizex, &sizey);
	prm->r.x = prm->r.x > sizex ? sizex : prm->r.x;
	prm->r.y = prm->r.y > sizey ? sizey : prm->r.y;
	prm->vars.win = mlx_new_window(prm->vars.mlx, prm->r.x, prm->r.y, "Cub3d");
	prm->screen.obj = mlx_new_image(prm->vars.mlx, prm->r.x, prm->r.y);
	prm->screen.data = (unsigned int *)mlx_get_data_addr(prm->screen.obj,
	&prm->screen.bpp, &prm->screen.sizeline, &prm->screen.endian);
	render_next_frame(prm);
}

int						start(char *file, int save)
{
	t_params		*prm;
	int				fd;

	prm = NULL;
	if ((fd = open(file, O_RDONLY)) < 0 ||
		ft_memcmp(&(file[ft_strlen(file) - 4]), ".cub", 3) != 0)
		ft_error(prm, fd, 1);
	if (!(prm = ft_parcer(prm, fd, 0, 0)))
		ft_error(prm, fd, 2);
	prm->vars.mlx = mlx_init();
	prm->dt_pics = ft_pars_pic(prm);
	if (save == 1)
	{
		ft_save(prm);
		return (0);
	}
	first_frame(prm);
	mlx_hook(prm->vars.win, 2, 1L << 0, ft_action, prm);
	mlx_loop_hook(prm->vars.win, render_next_frame, prm);
	mlx_hook(prm->vars.win, 17, 0, ft_exit, prm);
	mlx_loop(prm->vars.mlx);
	return (0);
}

int						main(int argc, char *argv[])
{
	int		res;

	res = 0;
	if (argc == 1 || argc > 3)
	{
		ft_error(NULL, 0, 0);
	}
	if (argc == 2)
	{
		res = start(argv[1], 0);
	}
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) == 6 &&
		ft_strncmp_181(argv[2], "––save", 6) == 0)
		{
			res = start(argv[1], 1);
		}
		else
			ft_error(NULL, 0, 4);
	}
	return (res);
}
