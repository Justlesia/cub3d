/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:56:39 by sbrenton          #+#    #+#             */
/*   Updated: 2021/01/26 21:41:41 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUM3D_CUB3D_H
#define CUM3D_CUB3D_H

#	include <stdlib.h>
#	include <unistd.h>
#	include <stdio.h>
#	include <zconf.h>
//#include "libft/libft.h"

struct		s_resolution
{
	int x;
	int y;
};
typedef struct s_resolution t_resolution;

struct		s_color
{
	int r;
	int g;
	int b;
};
typedef struct s_color t_color;

struct		s_params
{
	t_resolution			r;
	char					*we;
	char					*no;
	char					*so;
	char					*ea;
	char					*s;
	t_color f;
	t_color c;
	char					**map;
};
typedef struct s_params	t_params;

t_params *ft_parcer(t_params *prm, int fd);

#endif
