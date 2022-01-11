/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:29:27 by armendes          #+#    #+#             */
/*   Updated: 2022/01/11 17:02:45 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define EMPTY_ERR "One of the arguments is empty"
# define NOT_INT_ERR "One of the arguments is not an integer"
# define OVERFLOW_ERR "One of the arguments is too big for an integer"
# define DUP_ERR "Two arguments are the same"
# define MALLOC_ERR "Memory allocation error"

# define WHITE_SPACE " \t\n\v\f\r"

typedef struct s_list
{
	int				value;
	int				pos;
	struct s_list	*next;
}				t_list;

void	bubble_sort(int *tab, int size);
void	error(char *err_msg);
void	error_stack(t_list *input, char *err_msg);
void	free_tab(char **tab);
int		check_arg(int argc, char **argv);

#endif