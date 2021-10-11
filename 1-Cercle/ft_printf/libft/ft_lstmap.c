/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:36:33 by armendes          #+#    #+#             */
/*   Updated: 2020/12/15 16:52:17 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*elem;
	t_list	*begin;

	tmp = lst;
	if (lst == NULL)
		return (NULL);
	if ((elem = ft_lstnew((*f)(tmp->content))) == NULL)
		return (NULL);
	begin = elem;
	while (tmp->next)
	{
		tmp = tmp->next;
		if ((elem = ft_lstnew((*f)(tmp->content))) == NULL)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		ft_lstadd_back(&begin, elem);
	}
	return (begin);
}
