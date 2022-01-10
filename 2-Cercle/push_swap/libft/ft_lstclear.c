/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:28:24 by armendes          #+#    #+#             */
/*   Updated: 2022/01/10 19:11:04 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}
