/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:35:36 by armendes          #+#    #+#             */
/*   Updated: 2022/03/08 19:08:19 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parsing(char *line)
{
	t_cmd	*cmd;

	if (check_quote(line))
		error(NULL, QUOTE_ERR);
	cmd = find_pipe(line);
	if (!cmd)
		error(&cmd, CMD_ERR);
	if (cut_into_words(&cmd))
		error(&cmd, WORD_ERR);
	if (make_args(&cmd))
		error(&cmd, ARG_ERR);

////////////////////////////////
	t_cmd	*tmp = cmd;
	while (tmp)
	{
		write(0, tmp->cmd, ft_strlen(tmp->cmd));
		write(0, "--\n", 3);
		tmp = tmp->next;
	}
	write(0, "-\n", 2);
	t_cmd	*tmp2 = cmd;
	while (tmp2)
	{
		while (tmp2->words)
		{
			write(0, tmp2->words->word, ft_strlen(tmp2->words->word));
			write(0, "++\n", 3);
			if (tmp2->words->type == ARG)
				write(0, "type = arg_nothing++\n", 21);
			if (tmp2->words->type == ARG_IN_SIMPLE)
				write(0, "type = arg_simple++\n", 20);
			if (tmp2->words->type == ARG_IN_DOUBLE)
				write(0, "type = arg_double++\n", 20);
			if (tmp2->words->type == RED_IN)
				write(0, "type = redirection input++\n", 27);
			if (tmp2->words->type == RED_OUT)
				write(0, "type = redirection output\n", 26);
			if (tmp2->words->type == HERE_DOC)
				write(0, "type = here doc++\n", 18);
			if (tmp2->words->type == RED_OUT_APPEND)
				write(0, "type = redirection output append++\n", 35);
			if (tmp2->words->type == INFILE)
				write(0, "type = input file++\n", 20);
			if (tmp2->words->type == OUTFILE)
				write(0, "type = output file++\n", 21);
			if (tmp2->words->type == LIMITOR)
				write(0, "type = limitor++\n", 17);
			if (tmp2->words->type == OUTFILE_APPEND)
				write(0, "type = output file append++\n", 28);
			if (tmp2->words->need_to_concat == 0)
				write(0, "need_to_concat = 0++\n", 21);
			if (tmp2->words->need_to_concat == 1)
				write(0, "need_to_concat = 1++\n", 21);
			tmp2->words = tmp2->words->next;
		}
		write(0, "+\n", 2);
		tmp2 = tmp2->next;
	}
	// t_cmd	*tmp3 = cmd;
	// int		i = 0;
	// while (tmp3)
	// {
	// 	while (tmp3->args[i])
	// 	{
	// 		write(0, tmp3->args[i], ft_strlen(tmp3->args[i]));
	// 		write(0, "==\n", 3);
	// 		i++;
	// 	}
	// 	i = 0;
	// 	tmp3 = tmp3->next;
	// }
	// write(0, "=\n", 2);
//////////////////////

	// char	*buff = NULL;
	// getcwd(buff, 2000);
	// write(0, buff, 2000);
	// free(buff);
	free_all(&cmd);
}

int	main(void)
{
	char	*line;

	line = "";
	while (line)
	{
		line = readline("~>");
		parsing(line);
	}
	free(line);
	return (0);
}
