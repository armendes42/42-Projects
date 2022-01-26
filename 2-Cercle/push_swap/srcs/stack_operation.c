/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:18:04 by armendes          #+#    #+#             */
/*   Updated: 2022/01/26 15:31:27 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*tmp;
	t_list	*last;

	if (lstsize(*a) < 2)
		return ;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	tmp = *a;
	*a = (*a)->next;
	last->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (a == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*b == NULL)
	{
		*b = tmp;
		(*b)->next = NULL;
	}
	else
	{
		tmp->next = *b;
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

void	sa(t_list **a)
{
	t_list	*tmp;

	if (lstsize(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	write(1, "sa\n", 3);
}

void	rra(t_list **a)
{
	t_list	*last;
	t_list	*before_last;

	if (lstsize(*a) < 2)
		return ;
	before_last = *a;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = *a;
	before_last->next = NULL;
	*a = last;
	write(1, "rra\n", 4);
}
