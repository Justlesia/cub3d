/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/03/10 21:50:25 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "cub3d.h"

void		ft_destroy(t_texture img)
{
	free(img.obj);
	img.data = NULL;
}

t_texture	ft_pics_to_date(char *relative_path, t_vars vars)
{
	t_texture img;

	if (!(img.obj = mlx_xpm_file_to_image(vars.mlx, relative_path,
					&img.img_width, &img.img_height)))
	{
		img.data = NULL;
		return (img);
	}
	img.data = (unsigned int *)mlx_get_data_addr(img.obj, &(img.bpp),
								&(img.sizeline), &(img.endian));
	return (img);
}

t_dt_pics	ft_pars_pic_end(t_params *prm, t_dt_pics pics)
{
	pics.no = ft_pics_to_date(prm->p_pics.no, prm->vars);
	if (pics.no.data == NULL)
	{
		ft_destroy(pics.s);
		ft_destroy(pics.so);
		ft_destroy(pics.ea);
		ft_error(prm, 0, 3);
		return (pics);
	}
	pics.we = ft_pics_to_date(prm->p_pics.we, prm->vars);
	if (pics.we.data == NULL)
	{
		ft_destroy(pics.s);
		ft_destroy(pics.so);
		ft_destroy(pics.ea);
		ft_destroy(pics.no);
		ft_error(prm, 0, 3);
	}
	return (pics);
}

t_dt_pics	ft_pars_pic(t_params *prm)
{
	t_dt_pics pics;

	pics.s = ft_pics_to_date(prm->p_pics.s, prm->vars);
	if (pics.s.data == NULL)
	{
		pics.s.data = NULL;
		ft_error(prm, 0, 3);
		return (pics);
	}
	pics.so = ft_pics_to_date(prm->p_pics.so, prm->vars);
	if (pics.so.data == NULL)
	{
		ft_destroy(pics.s);
		ft_error(prm, 0, 3);
		return (pics);
	}
	pics.ea = ft_pics_to_date(prm->p_pics.ea, prm->vars);
	if (pics.ea.data == NULL)
	{
		ft_destroy(pics.s);
		ft_destroy(pics.so);
		ft_error(prm, 0, 3);
		return (pics);
	}
	return (ft_pars_pic_end(prm, pics));
}
