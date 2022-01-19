/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:29:27 by armendes          #+#    #+#             */
/*   Updated: 2022/01/19 18:14:23 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				pos;
	struct s_list	*next;
}				t_list;

void	error(void);
void	free_char_tab(char **tab);
void	free_stack(t_list **stack);
int		check_arg(int argc, char **argv);
t_list	*set_stack_a(int argc, char **argv);
int		check_sorted(t_list **stack);
int		check_duplicate(t_list **stack);
void	get_pos_stack(t_list **stack);
int		binary_search(int *tab, int value, int size);
int		len_stack(t_list **stack);
void	sort_big_stack(t_list **stack_a);
void	sort_small_stack(t_list **stack_a);
void	ra(t_list **a);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	sa(t_list **a);
void	rra(t_list **a);
int		lstsize(t_list *lst);
void	sort_stack_two(t_list **a);
void	sort_stack_three(t_list **a);
void	sort_stack_four(t_list **a);
void	sort_stack_five(t_list **a);
int		lstsort(t_list *a);
void	extract_zero_pos_four(t_list **a, t_list **b);
void	extract_zero_pos_five(t_list **a, t_list **b);
void	extract_one_pos_five(t_list **a, t_list **b);

#endif