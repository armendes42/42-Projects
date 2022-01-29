/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:46:06 by armendes          #+#    #+#             */
/*   Updated: 2022/01/29 17:12:51 by armendes         ###   ########.fr       */
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
	int		i;
	int		j;

	i = 0;
	b = NULL;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->pos >> i) & 1) == 1)
				ra(a);
			else
				pb(a, &b);
			j++;
		}
		while (b != NULL)
			pa(a, &b);
		i++;
	}
}

void	sort_big_stack(t_list **stack_a)
{
	int	size;
	int	max_bits;

	size = len_stack(stack_a);
	if (size <= 0)
		error();
	max_bits = search_max_bits(size);
	radix_sort(stack_a, size, max_bits);
}
