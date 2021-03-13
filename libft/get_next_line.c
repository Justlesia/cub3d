/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:11:53 by sbrenton          #+#    #+#             */
/*   Updated: 2021/03/08 17:01:06 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*ft_realloc(char *text)
{
	int		len;
	int		k;
	char	*tmp;

	len = ft_strlen(text);
	tmp = (char *)malloc(BUFFER_SIZE + len + 1);
	if (!(tmp))
		return (NULL);
	k = 0;
	while (k < len)
	{
		tmp[k] = text[k];
		k++;
	}
	tmp[k] = 0;
	free(text);
	return (tmp);
}

static char				*ft_search_in_tail(char *line, char **tail)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*tail)[i] != '\n' && (*tail)[i] != 0)
		i++;
	if ((*tail)[i] == '\n')
	{
		(*tail)[i] = 0;
		tmp = *tail;
		line = ft_strdup(*tail);
		*tail = ft_strdup(&(*tail)[i + 1]);
		free(tmp);
	}
	return (line);
}

static int				ft_fin(char **line, char **tail, int l)
{
	if (l == 0)
	{
		*line = ft_strdup(*tail);
		free(*tail);
		*tail = NULL;
		return (0);
	}
	return (-1);
}

int						get_next_line(int fd, char **line)
{
	static char	*tail;
	int			i;
	int			l;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	*line = NULL;
	if (!tail)
		if (!(tail = ft_strdup("")))
			return (-1);
	if ((*line = ft_search_in_tail(*line, &tail)))
		return (1);
	i = ft_strlen(tail);
	while (!*line)
	{
		if (!(tail = ft_realloc(tail)))
			return (-1);
		if ((l = read(fd, &(tail[i]), BUFFER_SIZE)) < 1)
			return (ft_fin(line, &tail, l));
		i = i + l;
		tail[i] = 0;
		if ((*line = ft_search_in_tail(*line, &tail)))
			return (1);
	}
	return (-1);
}
