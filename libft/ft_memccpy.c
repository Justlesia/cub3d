/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 01:04:38 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 01:04:38 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t l;

	l = 0;
	while (l < n)
	{
		((unsigned char *)dst)[l] = ((unsigned char *)src)[l];
		if (((unsigned char *)src)[l] == (unsigned char)c)
			return (&(((unsigned char *)dst)[l + 1]));
		l++;
	}
	return (NULL);
}
