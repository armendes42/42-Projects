/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:20:27 by armendes          #+#    #+#             */
/*   Updated: 2022/01/29 17:03:11 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	binary_search(int *tab, int value, int size)
{
	int	first_index;
	int	last_index;
	int	middle_index;

	first_index = 0;
	last_index = size - 1;
	while (first_index <= last_index)
	{
		middle_index = (first_index + last_index) / 2;
		if (tab[middle_index] == value)
			return (middle_index);
		if (value < tab[middle_index])
			last_index = middle_index - 1;
		else
			first_index = middle_index + 1;
	}
	return (0);
}

int	len_stack(t_list **stack)
{
	int		i;
	t_list	*tmp;

	if (stack == NULL || *stack == NULL)
		return (0);
	if ((*stack)->next == NULL)
		return (1);
	tmp = *stack;
	i = 0;
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	i++;
	return (i);
}

int	lstsize(t_list *lst)
{
	t_list	*tmp;
	int		result;

	if (lst == NULL)
		return (0);
	result = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		result++;
		tmp = tmp->next;
	}
	return (result);
}

int	lstsort(t_list *a)
{
	t_list	*tmp;

	if (a == NULL)
		return (0);
	tmp = a;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
