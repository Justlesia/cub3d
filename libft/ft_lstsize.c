/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 00:41:36 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 00:41:36 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list		*temp;
	int			count;

	count = 1;
	temp = lst;
	if (temp == NULL)
	{
		return (0);
	}
	while (temp->next)
	{
		count = count + 1;
		temp = temp->next;
	}
	return (count);
}
