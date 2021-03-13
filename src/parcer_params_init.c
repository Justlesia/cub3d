/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_params_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/03/12 20:18:50 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "cub3d.h"

char				*ft_mystrim(char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line, " ");
	return (tmp);
}

char				*ft_safe_l(char *line)
{
	char *tmp;

	tmp = line;
	line = ft_mystrim(tmp);
	free(tmp);
	return (line);
}

t_map				ft_protect_map(t_map map_t, int cnt_r)
{
	map_t.self = ft_protect(map_t.self, cnt_r);
	map_t.self = NULL;
	return (map_t);
}

t_params			*ft_init(t_params *prm)
{
	if (!(prm = (t_params *)malloc(sizeof(t_params))))
		return (NULL);
	prm->r.x = -1;
	prm->r.y = -1;
	prm->p_pics.no = NULL;
	prm->p_pics.we = NULL;
	prm->p_pics.so = NULL;
	prm->p_pics.ea = NULL;
	prm->p_pics.s = NULL;
	prm->f.r = -1;
	prm->f.g = -1;
	prm->f.b = -1;
	prm->c.r = -1;
	prm->c.g = -1;
	prm->c.b = -1;
	prm->map.self = NULL;
	prm->map.r = -1;
	prm->map.c = NULL;
	prm->player.r = -1;
	prm->player.c = -1;
	prm->player.view = 0;
	return (prm);
}

double				ft_start_dir(char position)
{
	if (position == 'N')
	{
		return (270 * M_PI / 180);
	}
	if (position == 'W')
	{
		return (180 * M_PI / 180);
	}
	if (position == 'S')
	{
		return (90 * M_PI / 180);
	}
	return (0);
}
