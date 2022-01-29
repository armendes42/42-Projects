/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:40:15 by armendes          #+#    #+#             */
/*   Updated: 2022/01/29 17:12:48 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc > 1)
	{
		stack_a = NULL;
		check_arg(argc, argv);
		set_stack_a(&stack_a, argc, argv);
		if (check_duplicate(&stack_a) == -1)
		{
			free_stack(&stack_a);
			error();
		}
		if (check_sorted(&stack_a) == 0)
			return (0);
		get_pos_stack(&stack_a);
		if (lstsize(stack_a) <= 5)
			sort_small_stack(&stack_a);
		else
			sort_big_stack(&stack_a);
		free_stack(&stack_a);
	}
	return (0);
}
