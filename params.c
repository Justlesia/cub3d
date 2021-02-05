/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/02/05 13:09:10 by sbrenton         ###   ########.fr       */
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
	prm->player=ft_player(&prm->map);
	if (prm->player.r == -1)
		return NULL;
	return prm;
}
