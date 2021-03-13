/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 00:02:26 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/06 00:02:26 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *i;

	i = (t_list *)malloc(sizeof(t_list));
	if (i != NULL)
	{
		(*i).content = content;
		(*i).next = NULL;
	}
	return (i);
}
