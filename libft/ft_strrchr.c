/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 02:47:33 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 02:47:33 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	size_t		s;
	size_t		n;
	int			found;

	s = (int)ft_strlen(str);
	n = 0;
	found = -1;
	while (n <= s)
	{
		if (str[n] == (unsigned char)c)
			found = n;
		n++;
	}
	if (found == -1)
	{
		return (NULL);
	}
	return (&str[found]);
}
