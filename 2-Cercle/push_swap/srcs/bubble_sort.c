/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:26:39 by armendes          #+#    #+#             */
/*   Updated: 2022/01/10 16:27:29 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(int *tab, int size)
{
	int nb_compare;
	int count;

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