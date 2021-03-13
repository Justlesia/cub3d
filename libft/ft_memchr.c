/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 02:16:16 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 02:16:16 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t l;

	l = 0;
	while (l < n)
	{
		if (((char *)s)[l] == (char)c)
		{
			return (void *)&s[l];
		}
		l++;
	}
	return (NULL);
}
