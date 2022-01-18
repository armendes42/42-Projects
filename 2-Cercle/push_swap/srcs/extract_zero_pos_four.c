/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_zero_pos_four.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:19:25 by armendes          #+#    #+#             */
/*   Updated: 2022/01/18 20:19:16 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	extract_zero_second_pos(t_list **a, t_list **b)
{
	sa(a);
	if (lstsort(*a))
		return ;
	pb(a, b);
}

static void	extract_zero_third_pos(t_list **a, t_list **b)
{
	ra(a);
	ra(a);
	if (lstsort(*a))
		return ;
	pb(a, b);
}

static void	extract_zero_last_pos(t_list **a, t_list **b)
{
	rra(a);
	if (lstsort(*a))
		return ;
	pb(a, b);
}

void	extract_zero_pos_four(t_list **a, t_list **b)
{
	if ((*a)->pos == 0)
		pb(a, b);
	else if ((*a)->next->pos == 0)
		extract_zero_second_pos(a, b);
	else if ((*a)->next->next->pos == 0)
		extract_zero_third_pos(a, b);
	else if ((*a)->next->next->next->pos == 0)
		extract_zero_last_pos(a, b);
}
