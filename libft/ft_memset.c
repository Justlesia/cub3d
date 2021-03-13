/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 02:32:06 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 02:32:06 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t n;

	n = 0;
	while (n < len)
	{
		((unsigned char *)b)[n] = (unsigned char)c;
		n++;
	}
	return (b);
}
