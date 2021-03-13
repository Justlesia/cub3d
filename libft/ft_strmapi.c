/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:44:50 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 16:44:50 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		n;
	size_t		len;
	char		*new;

	if (!s || !f)
		return (NULL);
	len = (int)ft_strlen(s);
	if (!(new = ft_calloc(len + 1, 1)))
		return (NULL);
	n = 0;
	while ((size_t)n < (size_t)len)
	{
		new[n] = f(n, s[n]);
		n++;
	}
	return (new);
}
