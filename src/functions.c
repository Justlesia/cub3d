/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/03/10 21:12:55 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "cub3d.h"

int						ft_is_in_set(const char *set, char c)
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

double					distance(double x1, double y1, double x2, double y2)
{
	double dist;

	dist = sqrtf(powf(x1 - x2, 2) + powf(y1 - y2, 2));
	return (dist);
}

char					**ft_protect(char **res, int w)
{
	while (w >= 0)
	{
		free(res[w]);
		w--;
	}
	free(res);
	return (NULL);
}

int						ft_strncmp_181(const char *s1, const char *s2, size_t n)
{
	size_t l;

	l = 0;
	while ((s1[l] != '\0' || s2[l] != '\0') && l < n)
	{
		if (s1[l] != s2[l])
		{
			return ((unsigned char)s1[l] - ((unsigned char)s2[l] - 181));
		}
		l++;
	}
	return (0);
}
