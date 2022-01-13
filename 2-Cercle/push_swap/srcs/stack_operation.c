/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:18:04 by armendes          #+#    #+#             */
/*   Updated: 2022/01/13 15:33:26 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (a == NULL || *a == NULL)
		return ;
	tmp = *a;
	tmp2 = (*a)->next->next;
	*a = (*a)->next;
	(*a)->next = tmp;
	tmp->next = tmp2;
	write(1, "ra\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (a == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if ((*b) == NULL)
	{
		*b = tmp;
		(*b)->next = NULL;
	}
	else
	{
		tmp->next = (*b);
		*b = tmp;
	}
	write(1, "pb\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (b == NULL)
		return ;
	tmp = (*b);
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}