/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:10:12 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 17:10:12 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list *temp;

	temp = NULL;
	temp = *(lst);
	if (!*(lst))
	{
		*(lst) = new;
		return ;
	}
	new->next = temp;
	*(lst) = new;
}
