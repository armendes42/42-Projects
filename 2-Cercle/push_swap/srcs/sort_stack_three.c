/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:51:22 by armendes          #+#    #+#             */
/*   Updated: 2022/01/18 20:18:34 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	last_pos_top(t_list **a)
{
	if ((*a)->next->pos == 0)
		ra(a);
	else
	{
		ra(a);
		sa(a);
	}
}

static void	middle_pos_top(t_list **a)
{
	if ((*a)->next->pos == 0)
		sa(a);
	else
		rra(a);
}

static void	first_pos_top(t_list **a)
{
	rra(a);
	sa(a);
}

void	sort_stack_three(t_list **a)
{
	if ((*a)->pos == 2)
		last_pos_top(a);
	else if ((*a)->pos == 1)
		middle_pos_top(a);
	else if ((*a)->pos == 0)
		first_pos_top(a);
}
