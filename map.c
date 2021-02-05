/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/02/05 13:08:10 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft/libft.h"
#	include "cub3d.h"
#	include <stdlib.h>
#	include <zconf.h>
#	include <fcntl.h>
# 	include "mlx_mms/mlx.h"

t_plr ft_player(t_map *map)
{
	int r;
	int c;
	t_plr player;
	int count;

	r = 0;
	count = 0;
	while(r < map->r)
	{
		c = 0;
		while(c < map->c[r])
		{
			if (ft_is_in_set("NSEW",map->self[r][c]) == 1)
			{
				player.r = r;
				player.c = c;
				player.view = map->self[r][c];
				map->self[r][c] = '0';
				count = count + 1;
				if (count == 2)
				{
					player.r = -1;
					return player;
				}
			}
			c++;
		}
		r++;
	}
	return player;
}

char **ft_check_map(char **map, int n_rows, int n_icol[n_rows + 1])
{
	int r;
	int c;

	int i;
	int j;

//проверить уголки на 1 и пропуск

	r = 0;
	while(r < n_rows)
	{
		c = 0;
		while(c < n_icol[r])
		{
//			if (ft_is_in_set("NSEW",map[r][c]) == 1)
//			{
//				map[r][c] = '0';
//			}
			if (ft_is_in_set("1 ",map[r][c]) == 0
				&& (r == 0 || r == n_rows-1 || c == 0 || c == n_icol[r]-1))
				return NULL;
			if (map[r][c] == ' ')
			{
				//sealed = 0;
				i = 0;
				while(r-i > 0)
				{
					if (map[r-i][c] == ' ')
						i++;
					else if (map[r-i][c] == '1')
					{
						if ( c == 0 || map[r-i][c-1] == '1' )
							break;
						return NULL;
					}
					else
						return NULL;
				}
				j = 0;
				while(c-j > 0)
				{
					if (map[r][c-j] == ' ')
						j++;
					else if (map[r][c-j] == '1')
					{
						if ( r == 0 || map[r-1][c-j] == '1')
							break;
						return NULL;
					}
					else
						return NULL;
				}
				i = 0;
				while(r+i < n_rows)
				{
					if (map[r+i][c] == ' ')
						i++;
					else if (map[r+i][c] == '1')
					{
						if ( c == n_icol[r]-1 || map[r+i][c+1] == '1')
							break;
						return NULL;
					}
					else
						return NULL;
				}
				j = 0;
				while(c+j < n_icol[r])
				{
					if (map[r][c+j] == ' ')
						j++;
					else if (map[r][c+j] == '1')
					{
						if ( r == n_rows-1 || map[r+1][c+j] == '1')
							break;
						return NULL;
					}
					else
						return NULL;
				}
			}
			c = c + 1;
		}
		r = r + 1;
	}
	return map;
}


int* ft_n_icol(int n_rows, int n_icol[n_rows + 1] )
{
	int *icol;
	int count_r;

	icol = 0;
	if (!(icol = (int*)malloc(sizeof(int) * (n_rows))))
			return (NULL);
	count_r = 0;
	while (count_r < n_rows)
	{
		icol[count_r] = n_icol[count_r];
		count_r++;
	}
	return icol;
}

t_map ft_map(t_list *list_map)
{
	t_map map_t;
	char **map;
	int n_rows;
	//int n_icol;

	map_t.self = NULL;

	//может сделать массив?
	int n_icol[1000];

	int count_r;
	int i;

	n_rows = ft_lstsize(list_map);
	if (!list_map || !(map = (char**)malloc(sizeof(char*) * (n_rows + 1))))
		return (map_t);
	count_r = 0;
	while (count_r < n_rows)
	{
		i = 0;
		n_icol[count_r] = ft_strlen((char *)list_map->content);
		if (!(map[count_r] = (char *)malloc(sizeof(char) * (n_icol[count_r] + 1))))
		{
			return map_t;
		}
		while ( i < n_icol[count_r] && (ft_is_in_set("102 NSEW",((char *)list_map->content)[i])== 1))
			{
				map[count_r][i] = ((char *)list_map->content)[i];
				i++;
			}
		map[count_r][i] = 0;
		if (i != n_icol[count_r] || ((char *)list_map->content)[i] != 0)
		//if (((char *)list_map->content)[i] != 0)
		{
			return map_t;
		}
		count_r++;
		if (count_r != n_rows)
			list_map = list_map->next;
	}
	if ((map_t.self = ft_check_map(map, n_rows, n_icol)) == NULL)
	{
		return map_t;
	}
	map_t.r = n_rows;
	map_t.c = ft_n_icol(n_rows, n_icol);

	return map_t;
}

