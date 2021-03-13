/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:06:11 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 13:06:11 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_in_set(const char *set, char c)
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

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		n;
	int		f;
	int		m;

	if (!s1 || !set)
		return (NULL);
	n = 0;
	while (s1[n] != '\0' && ft_is_in_set(set, s1[n]) == 1)
		n++;
	f = ft_strlen(s1) - 1;
	while (f >= 0 && ft_is_in_set(set, s1[f]) == 1 && f > n)
		f--;
	if (!(res = (char *)ft_calloc((f - n + 2), sizeof(char))))
		return (NULL);
	m = 0;
	while (n <= f)
	{
		res[m] = s1[n];
		m++;
		n++;
	}
	res[m] = '\0';
	return (res);
}
