/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 02:35:25 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 02:35:25 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	size_t s;
	size_t n;

	s = (int)ft_strlen(str);
	n = 0;
	while (n <= s)
	{
		if (str[n] == (unsigned char)c)
			return (&str[n]);
		n++;
	}
	return (NULL);
}
