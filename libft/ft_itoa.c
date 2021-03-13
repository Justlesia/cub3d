/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 21:47:46 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 21:47:46 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_res(int minus, int i, const char *temp)
{
	char		*res;
	int			j;

	if (!(res = (char *)ft_calloc(sizeof(char) * (i + minus + 1), 1)))
		return (NULL);
	j = 0;
	if (minus == 1)
	{
		res[j] = '-';
		j++;
	}
	while (j < (i + minus))
	{
		res[j] = temp[i - j - 1 + minus];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char			*ft_itoa(int n)
{
	long int	num;
	char		temp[20];
	int			i;
	int			minus;

	minus = 0;
	i = 0;
	num = (long int)n;
	if (num < 0)
	{
		num = num * -1;
		minus = 1;
	}
	while (num > 10)
	{
		temp[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	temp[i] = (num % 10) + '0';
	i++;
	if (num == 10)
		temp[i++] = '1';
	temp[i] = '\0';
	return (ft_res(minus, i, temp));
}
