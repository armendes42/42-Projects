/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:46:06 by armendes          #+#    #+#             */
/*   Updated: 2022/01/11 20:57:08 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_max_bits(int size)
{
	int	max_num;
	int	max_bits;

	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	radix_sort(t_list **a, int size, int max_bits)
{
	t_list	*b;
	int	i;
	int	j;
	int	num;

	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if ((num >> i) & 1 == 1)
				ra();
			else
				pb();
		}
	}
	while (ft_lstsize(b) > 0)
		pa();
}

void	sort_big_stack(t_list **stack_a)
{
	int	size;
	int	max_num;
	int	max_bits;

	size = len_stack(stack_a);
	max_bits = search_max_bits(size);
	radix_sort(stack_a, size, max_bits);
}
