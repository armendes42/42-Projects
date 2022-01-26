/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:51:13 by armendes          #+#    #+#             */
/*   Updated: 2022/01/26 15:29:54 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	last_pos_top(t_list **a)
{
	if ((*a)->next->pos == 1)
		ra(a);
	else
	{
		ra(a);
		sa(a);
	}
}

static void	middle_pos_top(t_list **a)
{
	if ((*a)->next->pos == 1)
		sa(a);
	else
		rra(a);
}

static void	first_pos_top(t_list **a)
{
	rra(a);
	sa(a);
}

static void	sort_three_numbers_left(t_list **a)
{
	if ((*a)->pos == 3)
		last_pos_top(a);
	else if ((*a)->pos == 2)
		middle_pos_top(a);
	else if ((*a)->pos == 1)
		first_pos_top(a);
}

void	sort_stack_four(t_list **a)
{
	t_list	*b;

	b = NULL;
	extract_zero_pos_four(a, &b);
	if (lstsort(*a) && (lstsize(*a) == 4))
		return ;
	sort_three_numbers_left(a);
	while (lstsize(b) >= 1)
		pa(a, &b);
	free_stack(&b);
}
