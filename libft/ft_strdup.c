/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 02:43:15 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 02:43:15 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		l;
	size_t		n;
	char		*res;

	l = ft_strlen(s);
	if (!(res = (char *)malloc(l + 1)))
		return (NULL);
	n = 0;
	while (n < l)
	{
		res[n] = s[n];
		n++;
	}
	res[n] = '\0';
	return (res);
}
