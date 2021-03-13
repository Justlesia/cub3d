/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/03/12 22:56:01 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "cub3d.h"

int			ft_parcer_outsource_r(t_params *prm, char *line, int *count)
{
	int mark;

	mark = 0;
	if (line[0] == 'R' && prm->r.x == -1 && prm->r.y == -1)
	{
		mark = 1;
		if (ft_r(prm, line, count) == -1)
			mark = -1;
		else
			free(line);
	}
	return (mark);
}

int			ft_parcer_outsource_no_so(t_params *prm, char *line, int *count)
{
	int mark;

	mark = 0;
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ' &&
		prm->p_pics.no == NULL)
	{
		mark = 1;
		if (!(prm->p_pics.no = ft_path(&(line[2]))))
			mark = -1;
		(*count)++;
		free(line);
	}
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ' &&
				prm->p_pics.so == NULL)
	{
		mark = 1;
		if (!(prm->p_pics.so = ft_path(&(line[2]))))
			mark = -1;
		(*count)++;
		free(line);
	}
	return (mark);
}

int			ft_parcer_outsource_we_ea(t_params *prm, char *line, int *count)
{
	int mark;

	mark = 0;
	if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ' &&
		prm->p_pics.we == NULL)
	{
		mark = 1;
		prm->p_pics.we = ft_path(&(line[2]));
		if (prm->p_pics.we == NULL)
			mark = -1;
		(*count)++;
		free(line);
	}
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ' &&
		prm->p_pics.ea == NULL)
	{
		mark = 1;
		if (!(prm->p_pics.ea = ft_path(&(line[2]))))
			mark = -1;
		(*count)++;
		free(line);
	}
	return (mark);
}

int			ft_parcer_outsource_f_c(t_params *prm, char *line, int *count)
{
	int mark;

	mark = 0;
	if (line[0] == 'F' && line[1] == ' ' && prm->f.r == -1 &&
			prm->f.g == -1 && prm->f.b == -1)
	{
		prm->f = ft_color(&(line[1]), prm->f);
		mark = 1;
		if (prm->f.r == -100)
			mark = -1;
		(*count)++;
		free(line);
	}
	else if (line[0] == 'C' && line[1] == ' ' && prm->c.r == -1 &&
				prm->c.g == -1 && prm->c.b == -1)
	{
		prm->c = ft_color(&(line[1]), prm->c);
		mark = 1;
		if (prm->c.r == -100)
			mark = -1;
		(*count)++;
		free(line);
	}
	return (mark);
}

int			ft_parcer_outsource_s_other(t_params *prm, char *line, int *count)
{
	int mark;

	mark = 0;
	if (line[0] == 'S' && line[1] == ' ' && prm->p_pics.s == NULL)
	{
		mark = 1;
		if (!(prm->p_pics.s = ft_path(&(line[1]))))
			mark = -1;
		(*count)++;
		free(line);
	}
	else if (line[0] == '\0')
	{
		free(line);
		mark = 1;
	}
	else
	{
		free(line);
		mark = -1;
	}
	return (mark);
}
