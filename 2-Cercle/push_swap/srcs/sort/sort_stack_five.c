/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:50:55 by armendes          #+#    #+#             */
/*   Updated: 2022/01/26 15:29:37 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	last_pos_top(t_list **a)
{
	if ((*a)->next->pos == 2)
		ra(a);
	else
	{
		ra(a);
		sa(a);
	}
}

static void	middle_pos_top(t_list **a)
{
	if ((*a)->next->pos == 2)
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
	if ((*a)->pos == 4)
		last_pos_top(a);
	else if ((*a)->pos == 3)
		middle_pos_top(a);
	else if ((*a)->pos == 2)
		first_pos_top(a);
}

void	sort_stack_five(t_list **a)
{
	t_list	*b;

	b = NULL;
	extract_zero_pos_five(a, &b);
	if (lstsort(*a) && (lstsize(*a) == 5))
		return ;
	extract_one_pos_five(a, &b);
	if (lstsort(*a) && (lstsize(*a) == 5))
		return ;
	sort_three_numbers_left(a);
	while (lstsize(b) >= 1)
		pa(a, &b);
	free_stack(&b);
}
