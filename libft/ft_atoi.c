/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 23:09:30 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 23:09:30 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_space_at(char i)
{
	if ((i >= 7 && i <= 13) || i == 32 || i == 0)
		return (1);
	else
		return (0);
}

static int				ft_prep_at(char *str)
{
	int			i;
	int			m;

	i = 0;
	m = 1;
	while (str[i] != '\0' && ft_space_at(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		m = -1;
		i++;
	}
	return (i * m);
}

int						ft_atoi(char *str)
{
	int			i;
	long long	pr;
	long long	nb;
	int			m;

	nb = 0;
	m = 1;
	if ((i = ft_prep_at(str)) < 0)
	{
		i = i * -1;
		m = -1;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		pr = nb;
		nb = nb * 10 + (str[i] - '0');
		i++;
		if (pr > nb && m == 1)
			return (-1);
		if (pr > nb && m == -1)
			return (0);
	}
	return (nb * m);
}
