/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:40:15 by armendes          #+#    #+#             */
/*   Updated: 2022/01/25 18:05:59 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = NULL;
	check_arg(argc, argv);
	stack_a = set_stack_a(argc, argv);
	if (!stack_a)
		error();
	if (check_duplicate(&stack_a))
	{
		free_stack(&stack_a);
		error();
	}
	if (!check_sorted(&stack_a))
		return (0);
	get_pos_stack(&stack_a);
	if (argc <= 6)
		sort_small_stack(&stack_a);
	else
		sort_big_stack(&stack_a);
	free_stack(&stack_a);
	return (0);
}
