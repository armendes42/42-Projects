/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:40:15 by armendes          #+#    #+#             */
/*   Updated: 2022/01/10 19:42:20 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	//t_list	*input;
	int		*tab_input;

	if (argc <= 1)
		error(NULL, ARGNB_ERR);
	tab_input = check_input(argc, argv);
	free(tab_input);
	//input = change_to_list(tab_input);
	/*if (check_sorted(input) == 0) 
		return (0);
	if (ft_lstsize(input) <= 5)
		sort_small_stack(input);
	else
		sort_big_stack(input);*/
	return (0);
}