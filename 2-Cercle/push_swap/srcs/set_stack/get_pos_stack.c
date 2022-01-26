/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:13:36 by armendes          #+#    #+#             */
/*   Updated: 2022/01/26 19:49:53 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_stack(t_list **stack)
{
	int		i;
	int		*copy;
	t_list	*tmp;

	if (stack == NULL || *stack == NULL)
		return (NULL);
	copy = malloc(sizeof(int) * len_stack(stack));
	if (!copy)
		return (NULL);
	tmp = *stack;
	i = 0;
	while (tmp->next != NULL)
	{
		copy[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	copy[i] = tmp->value;
	return (copy);
}

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	bubble_sort(int *tab, int size)
{
	int	nb_compare;
	int	count;

	nb_compare = size - 1;
	count = -1;
	while (nb_compare-- > 0)
	{
		while (count++ < nb_compare)
		{
			if (tab[count] > tab[count + 1])
			{
				swap(&tab[count], &tab[count + 1]);
			}
		}
		count = -1;
	}
}

void	get_pos_stack(t_list **stack)
{
	t_list	*tmp;
	int		*copy;
	int		len_stack_a;

	len_stack_a = len_stack(stack);
	copy = copy_stack(stack);
	if (!copy)
	{
		free_stack(stack);
		error();
	}
	bubble_sort(copy, len_stack_a);
	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp->pos = binary_search(copy, tmp->value, len_stack_a);
		tmp = tmp->next;
	}
	tmp->pos = binary_search(copy, tmp->value, len_stack_a);
	free(copy);
}
