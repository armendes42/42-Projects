/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:35:36 by armendes          #+#    #+#             */
/*   Updated: 2022/03/14 18:53:32 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parsing(char *line, t_info *info)
{
	int		control;

	if (check_quote(line))
		error(NULL, QUOTE_ERR);
	info->cmd = find_pipe(line);
	if (!(&info->cmd))
		error(&info->cmd, CMD_ERR);
	control = cut_into_words(info);
	if (control == -1)
		error(&info->cmd, WORD_ERR);
	else if (control == -2)
		return ;
	if (make_args(&info->cmd))
		error(&info->cmd, ARG_ERR);

////////////////////////////////
	t_cmd	*tmp = info->cmd;
	while (tmp)
	{
		write(0, tmp->cmd, ft_strlen(tmp->cmd));
		write(0, "--\n", 3);
		tmp = tmp->next;
	}
	write(0, "-\n", 2);
	t_cmd	*tmp2 = info->cmd;
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
	t_cmd	*tmp3 = info->cmd;
	int		i = 0;
	while (tmp3)
	{
		while (tmp3->args[i])
		{
			write(0, tmp3->args[i], ft_strlen(tmp3->args[i]));
			write(0, "==\n", 3);
			i++;
		}
		i = 0;
		tmp3 = tmp3->next;
	}
	write(0, "=\n", 2);
//////////////////////

	// char	*buff = NULL;
	// getcwd(buff, 2000);
	// write(0, buff, 2000);
	// free(buff);
	free_all(&info->cmd);
}

static char	**copy_env(char **envp)
{
	int		i;
	char	**env;

	i = 0;
	while (envp[i])
		i++;
	env = malloc(sizeof(char *) * (i + 1));
	if (!env)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_info	info;

	(void)argc;
	(void)argv;
	line = "";
	info.env = copy_env(envp);
	if (!info.env)
		error(NULL, ENV_ERR);
	while (line)
	{
		line = readline("~>");
		parsing(line, &info);
	}
	free(line);
	return (0);
}
