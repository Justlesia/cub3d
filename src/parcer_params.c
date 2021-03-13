/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_outsource.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/03/13 00:37:47 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "cub3d.h"

t_plr		ft_player(t_map *map, int count, int r, int c)
{
	t_plr player;

	while (++r < map->r)
	{
		c = -1;
		while (++c < map->c[r])
		{
			if (ft_is_in_set("NSEW", map->self[r][c]) == 1)
			{
				player.r = r + 0.5;
				player.c = c + 0.5;
				player.view = map->self[r][c];
				map->self[r][c] = '0';
				if ((count = count + 1) == 2)
				{
					player.r = -1;
					return (player);
				}
			}
		}
	}
	if (count == 0)
		player.r = -1;
	player.dir = ft_start_dir(player.view);
	return (player);
}

int			ft_r(t_params *prm, char *line, int *count)
{
	prm->r = ft_resolution(&(line[1]));
	if (prm->r.x == -1)
	{
		free(line);
		return (-1);
	}
	(*count)++;
	return (0);
}

t_list		*ft_before_map(char *line)
{
	t_list		*list_map;

	list_map = NULL;
	if (line[0] != '\0')
		ft_lstadd_back(&list_map, ft_lstnew(line));
	else
		free(line);
	return (list_map);
}

t_params	*ft_map_parce(t_params *prm, char *line, int fd, int r)
{
	t_list		*list_map;

	list_map = ft_before_map(line);
	while (r != 0)
	{
		r = get_next_line(fd, &line);
		if (list_map == NULL && line[0] == '\0')
		{
			free(line);
			continue;
		}
		else if (line[0] == '\0')
			ft_error_2(prm, fd, 4);
		else
			ft_lstadd_back(&list_map, ft_lstnew(line));
	}
	prm->map = ft_map(list_map, 0, 0);
	ft_lstclear(&list_map, free);
	if (prm->map.self == (NULL))
		return (NULL);
	prm->player = ft_player(&prm->map, 0, -1, -1);
	if (prm->player.r == -1)
		return (NULL);
	close(fd);
	return (prm);
}

t_params	*ft_parcer(t_params *prm, int fd, int count, int mark)
{
	char *line;

	prm = ft_init(prm);
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		line = ft_safe_l(line);
		if (count == 8)
			break ;
		mark = ft_parcer_outsource_r(prm, line, &count);
		if (mark == 0)
			mark = ft_parcer_outsource_no_so(prm, line, &count);
		if (mark == 0)
			mark = ft_parcer_outsource_we_ea(prm, line, &count);
		if (mark == 0)
			mark = ft_parcer_outsource_f_c(prm, line, &count);
		if (mark == 0)
			mark = ft_parcer_outsource_s_other(prm, line, &count);
		if (mark == 1)
			continue ;
		if (mark == -1)
			return (NULL);
	}
	return (ft_map_parce(prm, line, fd, 1));
}
