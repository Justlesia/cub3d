/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:12:23 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 23:12:23 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t		n;
	size_t		s1_len;
	size_t		s2_len;
	char		*res;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(res = (char *)ft_calloc((s1_len + s2_len), 1)))
		return (NULL);
	n = 0;
	while (n < s1_len)
	{
		res[n] = s1[n];
		n++;
	}
	n = 0;
	while (n < s2_len)
	{
		res[n + s1_len] = s2[n];
		n++;
	}
	res[n + s1_len] = '\0';
	return (res);
}
