/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 21:14:42 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 23:38:16 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t j;
	size_t len;

	j = 0;
	len = ft_strlen(dest);
	if (size < len)
	{
		return (ft_strlen(src) + size);
	}
	while (src[j] != '\0' && j + 1 < size - len)
	{
		dest[len + j] = src[j];
		j++;
	}
	if (size > len)
		dest[len + j] = '\0';
	return (len + ft_strlen(src));
}
