/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:06:36 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/09 21:06:36 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_mem(size_t size)
{
	void	*place;

	place = (void *)malloc(size * sizeof(void));
	if (!place)
	{
		place = NULL;
		return (place);
	}
	return (place);
}

void			*ft_calloc(size_t number, size_t size)
{
	int		*res;

	if (!(res = (void *)ft_mem(number * size)))
		return (NULL);
	ft_bzero(res, number * size);
	return (res);
}
