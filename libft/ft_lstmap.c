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

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;

	res = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp)
			ft_lstadd_back(&res, tmp);
		else
		{
			ft_lstclear(&res, del);
			free(res);
			return (NULL);
		}
		lst = lst->next;
	}
	return (res);
}
