/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:29:27 by armendes          #+#    #+#             */
/*   Updated: 2022/01/11 20:46:00 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
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
void	get_pos_stack(t_list **stack);
int		binary_search(int *tab, int value, int size);
int		len_stack(t_list **stack);

#endif