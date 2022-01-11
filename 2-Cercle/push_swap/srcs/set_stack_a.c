/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:02:48 by armendes          #+#    #+#             */
/*   Updated: 2022/01/11 20:31:00 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_first_node(t_list **stack_a, char *str)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return ;
	elem->value = ft_atoi(str);
	elem->next = NULL;
	elem->pos = -1;
	*stack_a = elem;
}

static void	set_next_node(t_list **stack_a, char *str)
{
	t_list	*elem;
	t_list	*tmp;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return ;
	elem->value = ft_atoi(str);
	elem->next = NULL;
	elem->pos = -1;
	tmp = *stack_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
}

static int	check_duplicate(t_list **stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (stack == NULL || *stack == NULL)
		return (1);
	if ((*stack)->next == NULL)
		return (0);
	tmp1 = *stack;
	while (tmp1->next != NULL)
	{
		tmp2 = tmp1->next;
		while(tmp2 != NULL)
		{
			if (tmp1->value == tmp2->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

t_list	*set_stack_a(int argc, char **argv)
{
	int		i;
	int		j;
	char	**tab;
	t_list	*stack_a;

	i = 0;
	stack_a = NULL;
	while (++i < argc)
	{
		j = -1;
		tab = ft_split(argv[i], " ");
		while (tab[++j])
		{
			if (stack_a == NULL)
				set_first_node(&stack_a, tab[j]);
			else
				set_next_node(&stack_a, tab[j]);
		}
		free_char_tab(tab);
	}
	if (check_duplicate(&stack_a))
	{
		free_stack(&stack_a);
		error();
	}
	return (stack_a);
}