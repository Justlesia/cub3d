/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 02:45:51 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 02:45:51 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t l;

	l = 0;
	while ((s1[l] != '\0' || s2[l] != '\0') && l < n)
	{
		if (s1[l] != s2[l])
		{
			return ((unsigned char)s1[l] - (unsigned char)s2[l]);
		}
		l++;
	}
	return (0);
}
