/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/03/09 19:39:58 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "cub3d.h"

void			ft_put_num(unsigned char *header, int n)
{
	header[0] = (unsigned char)(n % 256);
	header[1] = (unsigned char)(n / 256 % 256);
	header[2] = (unsigned char)(n / 256 / 256 % 256);
	header[3] = (unsigned char)(n / 256 / 256 / 256);
}

void			ft_header(t_params *prm, int img)
{
	int				n;
	unsigned char	header1[14];
	unsigned char	header2[40];

	n = 0;
	while (n < 14)
		header1[n++] = (unsigned char)(0);
	header1[0] = (unsigned char)(66);
	header1[1] = (unsigned char)(77);
	n = prm->r.x * prm->r.y * 4 + 54;
	ft_put_num(&header1[2], n);
	header1[10] = (unsigned char)(54);
	write(img, header1, 14);
	n = 0;
	while (n < 40)
		header2[n++] = (unsigned char)(0);
	header2[0] = (unsigned char)(40);
	ft_put_num(&header2[4], prm->r.x);
	ft_put_num(&header2[8], prm->r.y);
	header2[12] = (unsigned char)(1);
	header2[14] = (unsigned char)(32);
	write(img, header2, 40);
}

int				ft_save(t_params *prm)
{
	int		img;
	int		y;
	int		x;

	prm->screen.obj = mlx_new_image(prm->vars.mlx, prm->r.x, prm->r.y);
	prm->screen.data = (unsigned int *)mlx_get_data_addr(prm->screen.obj,
						&prm->screen.bpp, &prm->screen.sizeline,
						&prm->screen.endian);
	ft_basic_frame(prm, prm->screen);
	ft_walls(prm);
	img = open("image.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	ft_header(prm, img);
	y = prm->r.y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < prm->r.x)
			write(img, &prm->screen.data[y * prm->screen.sizeline / 4 + x++],
		4);
		y--;
	}
	close(img);
	ft_putstr_fd("Save image.bmp is successful\n", 1);
	ft_exit_esc(prm);
	return (0);
}
