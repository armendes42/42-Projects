/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_one_pos_five.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:59:12 by armendes          #+#    #+#             */
/*   Updated: 2022/01/18 20:19:24 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	extract_one_second_pos(t_list **a, t_list **b)
{
	sa(a);
	if (lstsort(*a))
		return ;
	pb(a, b);
}

static void	extract_one_third_pos(t_list **a, t_list **b)
{
	ra(a);
	ra(a);
	if (lstsort(*a))
		return ;
	pb(a, b);
}

static void	extract_one_last_pos(t_list **a, t_list **b)
{
	rra(a);
	if (lstsort(*a))
		return ;
	pb(a, b);
}

void	extract_one_pos_five(t_list **a, t_list **b)
{
	if ((*a)->pos == 1)
		pb(a, b);
	else if ((*a)->next->pos == 1)
		extract_one_second_pos(a, b);
	else if ((*a)->next->next->pos == 1)
		extract_one_third_pos(a, b);
	else if ((*a)->next->next->next->pos == 1)
		extract_one_last_pos(a, b);
}
