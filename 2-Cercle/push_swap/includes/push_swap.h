/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:29:27 by armendes          #+#    #+#             */
/*   Updated: 2022/01/10 19:41:14 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define ARG_ERR "One of the arguments is not an integer"
# define INT_ERR "One of the arguments is too big for an integer"
# define DUP_ERR "Two arguments are the same"
# define MALLOC_ERR "Memory allocation error"
# define ARGNB_ERR "Not enough arguments"

# define WHITE_SPACE " \t\n\v\f\r"

void	bubble_sort(int *tab, int size);
void	error(t_list *input, char *err_msg);
int		*check_input(int argc, char **argv);
t_list	*change_to_list(int *tab_input);
void	free_tab(char **tab);

#endif