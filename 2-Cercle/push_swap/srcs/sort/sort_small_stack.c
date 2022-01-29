/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:46:31 by armendes          #+#    #+#             */
/*   Updated: 2022/01/29 17:03:14 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_stack(t_list **a)
{
	if (lstsize(*a) == 2)
		sort_stack_two(a);
	else if (lstsize(*a) == 3)
		sort_stack_three(a);
	else if (lstsize(*a) == 4)
		sort_stack_four(a);
	else if (lstsize(*a) == 5)
		sort_stack_five(a);
}
