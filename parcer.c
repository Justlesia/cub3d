/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/01/27 06:23:40 by lesia            ###   ########.fr       */
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
	prm->no = 0;
	prm->we = 0;
	prm->so = 0;
	prm->ea = 0;
	prm->s = 0;
	prm->f.r = -1;
	prm->f.g = -1;
	prm->f.b = -1;
	prm->c.r = -1;
	prm->c.g = -1;
	prm->c.b = -1;
	prm->map = NULL;
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



int ft_check_map(char **map, int n_rows, int n_icol[n_rows + 1])
{
	int r;
	int c;
	int count;

	int i;
	int j;

//проверить уголки на 1 и пропуск

	r = 0;
	count = 0;
	while(r < n_rows)
	{
		c = 0;
		while(c < n_icol[r])
		{
			if (ft_is_in_set("1 ",map[r][c]) == 0
				&& (r == 0 || r == n_rows-1 || c == 0 || c == n_icol[r]-1))
				return -1;
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
						return -1;
					}
					else
						return -1;
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
						return -1;
					}
					else
						return -1;
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
						return -1;
					}
					else
						return -1;
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
						return -1;
					}
					else
						return -1;
				}
			}
			if (ft_is_in_set("NSEW",map[r][c]) == 1)
			{
				count = count + 1;
				if (count == 2)
					return 1;
			}
			c = c + 1;
		}
		r = r + 1;
	}
	if (count == 0)
		return 1;
	return 0;
}


char **ft_map(t_list *list_map)
{
	char **map;
	int n_rows;
	//int n_icol;

	//может сделать массив?
	int n_icol[1000];

	int count_r;
	int i;

	n_rows = ft_lstsize(list_map);
	if (!list_map || !(map = (char**)malloc(sizeof(char*) * (n_rows + 1))))
		return (NULL);
	count_r = 0;
	while (count_r < n_rows)
	{
		i = 0;
		n_icol[count_r] = ft_strlen(list_map->content);
		if (!(map[count_r] = (char *)malloc(sizeof(char) * (n_icol[count_r] + 1))))
		{
			return NULL;
		}
		while ( i < n_icol[count_r] && (ft_is_in_set("102 NSEW",((char *)list_map->content)[i])== 1))
			{
				map[count_r][i] = ((char *)list_map->content)[i];
				i++;
			}
		map[count_r][i] = 0;
		if (i != n_icol[count_r] || ((char *)list_map->content)[i] != 0)
		{
			return NULL;
		}
		count_r++;
		if (count_r != n_rows)
			list_map = list_map->next;
	}
	return ft_check_map(map, n_rows, n_icol) != 0 ? NULL : map;
}


t_params *ft_parcer(t_params *prm, int fd)
{
	char *line;
	t_list *list_map;
	int count;

	count = 0;

	if ((fd = open("/Users/lesia/Study/21_school/cum3d/params.cub", O_RDONLY)) < 0)
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
		else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ' && prm->no == NULL)
		{
			if (!(prm->no = ft_path(&(line[2]))))
				return NULL;
			count++;
		}
		else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ' && prm->so == NULL)
		{
			if (!(prm->so = ft_path(&(line[2]))))
				return NULL;
			count++;
		}
		else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ' && prm->we == NULL)
		{
			prm->we = ft_path(&(line[2]));
			if (prm->we == NULL)
				return NULL;
			count++;
		}
		else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ' && prm->ea == NULL)
		{
			if (!(prm->ea = ft_path(&(line[2]))))
				return NULL;
			count++;
		}
		else if (line[0] == 'S' && line[1] == ' '  && prm->s == NULL)
		{
			if (!(prm->s = ft_path(&(line[1]))))
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
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '\0')
			continue;
		else
			ft_lstadd_back(&list_map, ft_lstnew(line));
	}

	prm->map = ft_map(list_map);
	if (prm->map == NULL)
		return NULL;
	return prm;
}

//
//Resolution:
//R 1920 1080
//· identifier: R
//· x render size
//· y render size
//∗ North texture:
//NO ./path_to_the_north_texture
//· identifier: NO
//· path to the north texure
//∗ South texture:
//SO ./path_to_the_south_texture
//· identifier: SO
//· path to the south texure
//∗ West texture:
//WE ./path_to_the_west_texture
//· identifier: WE
//· path to the west texure
//∗ East texture:
//EA ./path_to_the_east_texture
//· identifier: EA
//· path to the east texure
//∗ Sprite texture:
//S ./path_to_the_sprite_texture
//· identifier: S
//· path to the sprite texure


//∗ Floor color:
//F 220,100,0
//· identifier: F
//· R,G,B colors in range [0,255]: 0, 255, 255
//7
//cub3D My first RayCaster with miniLibX
//∗ Ceilling color:
//C 225,30,0
//· identifier: C
//· R,G,B colors in range [0,255]: 0, 255, 255



//◦ Example of the mandatory part with a minimalist .cub scene:
//R 1920 1080
//NO ./path_to_the_north_texture
//		SO ./path_to_the_south_texture
//		WE ./path_to_the_west_texture
//		EA ./path_to_the_east_texture
//		S ./path_to_the_sprite_texture
//		F 220,100,0
//C 225,30,0
//1111111111111111111111111
//1000000000110000000000001
//1011000001110000002000001
//1001000000000000000000001
//111111111011000001110000000000001
//100000000011000001110111111111111
//11110111111111011100000010001
//11110111111111011101010010001
//11000000110101011100000010001
//10002000000000001100000010001
//10000000000000001101010010001
//11000001110101011111011110N0111
//11110111 1110101 101111010001
//11111111 1111111 111111111111
//◦ If any misconfiguration of any kind is encountered in the file, the program
//must exit properly and return "Error\n" followed by an explicit error message
//of your choice.
