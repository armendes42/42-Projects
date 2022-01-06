/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:40:15 by armendes          #+#    #+#             */
/*   Updated: 2022/01/06 15:27:12 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list	*input;

	if (argc <= 1)
		exit(EXIT_FAILURE);
	input = format(argv);  ////ecrire format() qui sert a formatter l'input et a verifier les erreurs d'input
	if (check_sorted(input) == 0) 
		return (0);
	if (ft_lstsize(input) <= 5)  ///ecrire intlen qui est strlen pour un tab int
		sort_small_stack(input);
	else
		sort_big_stack(input);
	return (0);
}