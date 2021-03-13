/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:23:00 by sbrenton          #+#    #+#             */
/*   Updated: 2021/02/03 12:35:41 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;

	temp = NULL;
	temp = *(lst);
	if (!*(lst))
	{
		*(lst) = new;
		return ;
	}
	else
	{
		while (temp->next)
		{
			temp = temp->next;
		}
	}
	temp->next = new;
}
