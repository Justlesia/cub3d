/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_params_units.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/03/10 14:56:04 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "cub3d.h"

char				*ft_safe_strm(char *line, char *tmp2)
{
	char *tmp;

	tmp = line;
	line = ft_mystrim(&(tmp[ft_strlen(tmp2)]));
	free(tmp);
	free(tmp2);
	return (line);
}

t_color				ft_color_end(char *line, t_color color)
{
	char *tmp;
	char *tmp2;

	if (line[0] == ',')
	{
		tmp = line;
		line = ft_mystrim(&(line[1]));
		free(tmp);
		color.b = ft_atoi(&(line[0]));
		tmp2 = ft_itoa(color.b);
		line = ft_safe_strm(line, tmp2);
	}
	if ((line[0] != '\0' || color.r < 0 || color.g < 0 || color.b < 0) ||
		(color.r > 256 || color.g > 256 || color.b > 256))
		color.r = -100;
	free(line);
	return (color);
}

t_color				ft_color(char *line, t_color color)
{
	char *tmp;
	char *tmp2;

	line = ft_mystrim(line);
	if (ft_is_in_set("0123456789", line[0]))
	{
		color.r = ft_atoi(line);
		tmp2 = ft_itoa(color.r);
		line = ft_safe_strm(line, tmp2);
	}
	if (line[0] == ',')
	{
		tmp = line;
		line = ft_mystrim(&(line[1]));
		free(tmp);
		color.g = ft_atoi(&(line[0]));
		tmp2 = ft_itoa(color.g);
		line = ft_safe_strm(line, tmp2);
	}
	return (ft_color_end(line, color));
}

char				*ft_path(char *line)
{
	line = ft_mystrim(line);
	if (line[0] != '.' || line[1] != '/')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

t_resolution		ft_resolution(char *line)
{
	t_resolution	r;
	char			*tmp;
	char			*tmp2;

	line = ft_mystrim(line);
	r.x = ft_atoi(line);
	tmp = line;
	tmp2 = ft_itoa(r.x);
	line = ft_mystrim(&(line[ft_strlen(tmp2)]));
	free(tmp);
	free(tmp2);
	r.y = ft_atoi(line);
	tmp = line;
	tmp2 = ft_itoa(r.y);
	line = ft_mystrim(&(line[ft_strlen(tmp2)]));
	free(tmp);
	free(tmp2);
	if (line[0] != '\0' || r.x <= 0 || r.y <= 0)
	{
		free(line);
		r.x = -1;
		return (r);
	}
	free(line);
	return (r);
}
