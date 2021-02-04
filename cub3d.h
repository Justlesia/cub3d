/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:56:39 by sbrenton          #+#    #+#             */
/*   Updated: 2021/02/04 19:11:53 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUM3D_CUB3D_H
#define CUM3D_CUB3D_H

#	include <stdlib.h>
#	include <unistd.h>
#	include <stdio.h>
#	include <zconf.h>
#include "libft/libft.h"

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

struct		s_pics
{
	char					*we;
	char					*no;
	char					*so;
	char					*ea;
	char					*s;
};
typedef struct s_pics t_pics;


struct		s_plr
{
	int					r;
	int					c;
	char				view;
};
typedef struct s_plr t_plr;


struct		s_map
{
	char				**self;
	int					r;
	int					*c;
};
typedef struct s_map t_map;


typedef struct  s_vars {
	void    *mlx;
	void    *win;
}               t_vars;

struct		s_params
{
	t_resolution			r;
	t_pics					p_pics;
	t_color f;
	t_color c;
	t_map					map;
	t_plr					player;
	t_vars 					vars;
};
typedef struct s_params	t_params;



t_params *ft_parcer(t_params *prm, int fd);
t_map ft_map(t_list *list_map);
t_plr ft_player(t_map map);
int ft_is_in_set(const char *set, char c);

#endif
