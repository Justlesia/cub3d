/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:57:38 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 14:57:38 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*n_s;
	unsigned char	*n_d;

	if (dst == NULL && src == NULL)
		return (dst);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
	{
		n_d = (unsigned char *)dst + len - 1;
		n_s = (unsigned char *)src + len - 1;
		while (len > 0)
		{
			*(n_d--) = *(n_s--);
			len--;
		}
	}
	return (dst);
}
