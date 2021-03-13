/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/03/13 00:06:09 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char						**ft_recursive(char **map, int r, int c, int n_rows)
{
	if (map[r][c] == '9' || map[r][c] == ' ')
	{
		map[0][0] = '4';
		return (map);
	}
	if (map[r][c] == '3' || map[r][c] == '1')
		return (map);
	map[r][c] = '3';
	map = ft_recursive(map, r + 1, c, n_rows);
	map = ft_recursive(map, r - 1, c, n_rows);
	map = ft_recursive(map, r, c + 1, n_rows);
	map = ft_recursive(map, r, c - 1, n_rows);
	map = ft_recursive(map, r + 1, c + 1, n_rows);
	map = ft_recursive(map, r - 1, c - 1, n_rows);
	map = ft_recursive(map, r - 1, c + 1, n_rows);
	map = ft_recursive(map, r + 1, c - 1, n_rows);
	return (map);
}

char						**ft_nine(char **copy_map,
							int n_rows, int max_icol)
{
	int			n;
	int			i;

	n = 0;
	while (n < n_rows + 2)
	{
		if (!(copy_map[n] = (char *)malloc(sizeof(char) * (max_icol + 3))))
			return (ft_protect(copy_map, n));
		i = 0;
		while (i < max_icol + 2)
		{
			copy_map[n][i] = '9';
			i++;
		}
		copy_map[n][i] = 0;
		n++;
	}
	return (copy_map);
}

char						**ft_copy_map(char **map, int n_rows,
						int n_icol[n_rows + 1], int max_icol)
{
	char		**copy_map;
	int			n;
	int			i;

	n = 0;
	while (n < n_rows)
	{
		max_icol = max_icol > n_icol[n] ? max_icol : n_icol[n];
		n++;
	}
	if (!(copy_map = (char**)malloc(sizeof(char*) * (n_rows + 3))))
		return (NULL);
	copy_map = ft_nine(copy_map, n_rows, max_icol);
	n = 0;
	while (n < n_rows)
	{
		i = 0;
		while (i < n_icol[n])
		{
			copy_map[n + 1][i + 1] = map[n][i];
			i++;
		}
		n++;
	}
	return (copy_map);
}

char						**ft_check_map(char **map, int n_rows,
								int n_icol[n_rows + 1], int r)
{
	int			c;
	char		**copy_map;

	copy_map = ft_copy_map(map, n_rows, n_icol, 0);
	r = 0;
	while (++r < n_rows)
	{
		c = 0;
		while (copy_map[r][++c] != '9')
		{
			if (ft_is_in_set("NSEW", copy_map[r][c]) == 1)
			{
				copy_map = ft_recursive(copy_map, r, c, n_rows + 2);
				if (copy_map[0][0] == '4')
				{
					map = ft_protect(map, n_rows);
					break ;
				}
			}
		}
		if (!map)
			break ;
	}
	ft_protect(copy_map, n_rows + 1);
	return (map);
}

t_map						ft_map(t_list *l_m, int i, int cnt_r)
{
	t_map			map_t;
	int				n_icol[1000];

	map_t.r = ft_lstsize(l_m);
	if (!l_m || !(map_t.self = (char**)malloc(sizeof(char*) * (map_t.r + 1))))
		return (map_t);
	while (cnt_r < map_t.r)
	{
		n_icol[cnt_r] = ft_strlen((char *)l_m->content);
		if (!(map_t.self[cnt_r] = (char *)malloc(sizeof(char)
				* (n_icol[cnt_r] + 1))))
			return (ft_protect_map(map_t, cnt_r));
		i = -1;
		while (++i < n_icol[cnt_r] &&
		(ft_is_in_set("102 NSEW", ((char *)l_m->content)[i]) == 1))
			map_t.self[cnt_r][i] = ((char *)l_m->content)[i];
		map_t.self[cnt_r][i] = 0;
		if (i != n_icol[cnt_r] || ((char *)l_m->content)[i] != 0)
			return (ft_protect_map(map_t, cnt_r));
		l_m = ++cnt_r != map_t.r ? l_m->next : l_m;
	}
	map_t.self[map_t.r] = 0;
	if ((map_t.self = ft_check_map(map_t.self, map_t.r, n_icol, 0)) != NULL)
		map_t.c = n_icol;
	return (map_t);
}
