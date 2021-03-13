/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 01:17:32 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 01:17:32 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t l;

	l = 0;
	while (l < n)
	{
		if (((char *)s1)[l] != ((char *)s2)[l])
		{
			return (((unsigned char *)s1)[l] - ((unsigned char *)s2)[l]);
		}
		l++;
	}
	return (0);
}
