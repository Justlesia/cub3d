/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 12:37:58 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 20:59:05 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t j;

	if (!dest || !src)
		return (0);
	j = 0;
	while (src[j] != '\0' && j + 1 < size)
	{
		dest[j] = src[j];
		j++;
	}
	if (size > 0)
		dest[j] = '\0';
	return (ft_strlen(src));
}
