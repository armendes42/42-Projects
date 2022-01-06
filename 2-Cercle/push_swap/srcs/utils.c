/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:50:20 by armendes          #+#    #+#             */
/*   Updated: 2022/01/06 15:24:53 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_list *tab)
{
	t_list	*tmp;

	tmp = tab->next;
	if (ft_lstsize(tab) == 1)
		return (0);
	while (tmp != NULL)
	{
		if (tab->value >= tmp->value)
			return (-1);
		tab = tmp;
		tmp = tab->next;
	}
	return (0);
}

int	binary_search(int *tab, int value)
{
	int	first_index;
	int	last_index;
	int	middle_index;

	first_index = 0;
	last_index = intlen(tab);
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