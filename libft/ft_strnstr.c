/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 02:46:57 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/09 02:46:57 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t i;
	size_t k;

	i = 0;
	if (!haystack && !needle)
		return (NULL);
	if (needle[0] == '\0')
		return ((char*)&haystack[0]);
	while (haystack[i] != '\0' && i < len)
	{
		k = 0;
		while (haystack[i + k] == needle[k] && (i + k) < len)
		{
			k = k + 1;
			if (needle[k] == '\0')
				return ((char*)&haystack[i]);
		}
		i = i + 1;
	}
	return (NULL);
}
