/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:45:25 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 16:45:25 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	char	*res;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (!(res = (char *)ft_calloc((len + 1), 1)))
		return (NULL);
	n = 0;
	if (start < ft_strlen(s))
	{
		while (n + start < len + start && s[n + start] != '\0')
		{
			res[n] = s[n + start];
			n++;
		}
	}
	res[n] = '\0';
	return (res);
}
