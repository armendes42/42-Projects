/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:57:55 by armendes          #+#    #+#             */
/*   Updated: 2022/01/26 15:14:20 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_list **stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (stack == NULL || *stack == NULL)
		return (-1);
	if ((*stack)->next == NULL)
	{
		free_stack(stack);
		return (0);
	}
	tmp1 = *stack;
	while (tmp1->next != NULL)
	{
		tmp2 = tmp1->next;
		if (tmp1->value > tmp2->value)
			return (-1);
		tmp1 = tmp1->next;
	}
	free_stack(stack);
	return (0);
}
