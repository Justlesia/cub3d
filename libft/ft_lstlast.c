/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:05:49 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 17:05:49 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *temp;

	temp = lst;
	if (temp == NULL)
	{
		return (0);
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}
