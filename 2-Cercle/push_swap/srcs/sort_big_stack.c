/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:46:06 by armendes          #+#    #+#             */
/*   Updated: 2022/01/10 19:13:29 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_sort(t_list *a)
{
	t_list	*b;
	int		size;
	int		max_bits;
	int		max_num;

	int	i;
	int	j;
	int	num;

	size = ft_lstsize(a);
	max_num = size - 1;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			num = (int)ft_lstlast(a)->content;
			if ((num >> i) & 1 == 1)
				ra();
			else
				pb();
		}
	}
	while (ft_lstsize(b) > 0)
		pa();
}

void	sort_big_stack(t_list *input)
{
	int		*tmp;
	t_list	*a;

	tmp = change_to_tab(input); /////ecrire change to tab qui transforme liste chainee en tab int 
	bubble_sort(tmp, ft_lstsize(input));
	while (input != NULL)
		input->content = binary_search(tmp, input->content);
	a = input;
	radix_sort(a);
}
