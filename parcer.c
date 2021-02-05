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

int ft_is_in_set(const char *set, char c)
{
	int n;

	n = 0;
	while (set[n] != '\0')
	{
		if (set[n] == c)
			return (1);
		n++;
	}
	return (0);
}

char * ft_mystrim(char *line)
{
	char *tmp;

	tmp = ft_strtrim(line, " ");
//	free(line);
	return tmp;
}

t_params * ft_init(t_params *prm)
{
	if (!(prm = (t_params *)malloc(sizeof(t_params))))
		return NULL;
	prm->r.x = -1;
	prm->r.y = -1;
	prm->p_pics.no = 0;
	prm->p_pics.we = 0;
	prm->p_pics.so = 0;
	prm->p_pics.ea = 0;
	prm->p_pics.s = 0;
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
	return prm;
}

t_color ft_color(char *line, t_color color)
{
	line = ft_mystrim(line);
	if (ft_is_in_set("0123456789", line[0]))
	{
		color.r = ft_atoi(line);
		line = ft_mystrim(&(line[ft_strlen(ft_itoa(color.r))]));
	}
	if (line[0] == ',')
	{
		color.g = ft_atoi(&(line[1]));
		line = ft_mystrim(&(line[1 + ft_strlen(ft_itoa(color.g))]));
	}
	if (line[0] == ',')
	{
		color.b = ft_atoi(&(line[1]));
		line = ft_mystrim(&(line[1 + ft_strlen(ft_itoa(color.b))]));
	}
	if ((line[0] != '\0' || color.r < 0 || color.g < 0 || color.b < 0) ||
	(color.r > 256 || color.g > 256 || color.b > 256))
	{
		color.r = -100;
	}
//	free(line);
	return (color);
}

char *ft_path(char *line)
{
	line = ft_mystrim(line);
	if (line[0] != '.' || line[1] != '/')
	{
//		free(line);
		return(NULL);
	}
	return (line);
}

t_plr ft_player(t_map map)
{
	int r;
	int c;
	t_plr player;
	int count;

	r = 0;
	count = 0;
	while(r < map.r)
	{
		c = 0;
		while(c < map.c[r])
		{
			if (ft_is_in_set("NSEW",map.self[r][c]) == 1)
			{
				player.r = r;
				player.c = c;
				player.view = map.self[r][c];
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
			if (ft_is_in_set("NSEW",map[r][c]) == 1)
			{
				map[r][c] = 0;
			}
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

t_params *ft_parcer(t_params *prm, int fd)
{
	char *line;
	t_list *list_map;
	int count;

	count = 0;

	if ((fd = open("/Users/sbrenton/Documents/Study/cub_school/p.cub", O_RDONLY)) < 0)
		return NULL;

	prm = ft_init(prm);
	if (!(line = (char *)malloc(sizeof(char *))))
		return NULL;
	while (get_next_line(fd, &line) > 0)
	{
		line = ft_mystrim(line);
		if (line[0] == 'R' && prm->r.x == -1 && prm->r.y == -1)
		{
			//printf("%d", mlx_get_screen_size(mlx_ptr, int *sizex, int *sizey);)
			line = ft_mystrim(&(line[1]));
			prm->r.x =  ft_atoi(line);
			line = ft_mystrim(&(line[ft_strlen(ft_itoa(prm->r.x))]));
			prm->r.y =  ft_atoi(line);
			line = ft_mystrim(&(line[ft_strlen(ft_itoa(prm->r.y))]));
			if (line[0] != '\0' || prm->r.x < 0 || prm->r.y < 0 )
			{
//				free(line);
				return 0;
			}
			count++;

		}
		else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ' && prm->p_pics.no == NULL)
		{
			if (!(prm->p_pics.no = ft_path(&(line[2]))))
				return NULL;
			count++;
		}
		else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ' && prm->p_pics.so == NULL)
		{
			if (!(prm->p_pics.so = ft_path(&(line[2]))))
				return NULL;
			count++;
		}
		else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ' && prm->p_pics.we == NULL)
		{
			prm->p_pics.we = ft_path(&(line[2]));
			if (prm->p_pics.we == NULL)
				return NULL;
			count++;
		}
		else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ' && prm->p_pics.ea == NULL)
		{
			if (!(prm->p_pics.ea = ft_path(&(line[2]))))
				return NULL;
			count++;
		}
		else if (line[0] == 'S' && line[1] == ' '  && prm->p_pics.s == NULL)
		{
			if (!(prm->p_pics.s = ft_path(&(line[1]))))
				return NULL;
			count++;
		}
		else if (line[0] == 'F' && line[1] == ' ' && prm->f.r == -1 && prm->f.g == -1 && prm->f.b == -1)
		{
			prm->f = ft_color(&(line[1]), prm->f);
			if (prm->f.r == -100)
				return(NULL);
			count++;
		}
		else if (line[0] == 'C' && line[1] == ' ' && prm->c.r == -1 && prm->c.g == -1 && prm->c.b == -1)
		{
			prm->c = ft_color(&(line[1]), prm->c);
			if (prm->c.r == -100)
				return NULL;
			count++;
		}
		else if (line[0] == '\0')
			continue;
		else
		{
//			free(line);
			return NULL;
		}
		if (count == 8)
			break;
//		free(line);
		line = (char *)malloc(sizeof(char *));
	}
	list_map = NULL;
	int r = 1;
	while (r != 0)
	{
		r = get_next_line(fd, &line);
		if (line[0] == '\0')
			continue;
		else
			ft_lstadd_back(&list_map, ft_lstnew(line));
	}
	prm->map = ft_map(list_map);
	if (prm->map.self == NULL)
		return NULL;
	prm->player= ft_player(&(prm->map));
	if (prm->player.r == -1)
		return NULL;
	prm->p_cam = ft_camera_params(prm->player.view);
	return prm;
}
