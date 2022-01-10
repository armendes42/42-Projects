/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:22:04 by armendes          #+#    #+#             */
/*   Updated: 2020/11/30 20:52:24 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst == NULL || new == NULL)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		tmp = ft_lstlast(*alst);
		tmp->next = new;
	}
}
