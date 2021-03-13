/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 01:20:16 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 01:20:16 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long l;

	l = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (l < n)
	{
		((char *)dst)[l] = ((char *)src)[l];
		l++;
	}
	return (dst);
}
