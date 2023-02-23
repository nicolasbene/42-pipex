/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:44:15 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/23 17:17:53 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_cmd(char **cmd_paths, char *arg_main)
{
	char	*tmp;
	char	*command;

	while (*cmd_paths)
	{
		tmp = ft_strjoin(*cmd_paths, "/");
		command = ft_strjoin(tmp, arg_main);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		dprintf(2, "command : %s\n", command);
		free(command);
		cmd_paths++;
	}
	return (NULL);
}

void	first_child(t_pipex *pipex, char *argv[], char *envp[])
{
	dup2(pipex->tube[1], 1);
	close(pipex->tube[0]);
	dup2(pipex->infile, 0);
	pipex->cmd_arg_str = ft_split(argv[2], ' ');
	int i = 0;
	pipex->cmd_str = get_cmd(pipex->cmd_paths, pipex->cmd_arg_str[0]);
		while (pipex->cmd_paths[i])
	{
		dprintf(2, "cmd_path : %s\n", pipex->cmd_paths[i]);
		i++;
	}
	dprintf(2, "\n---------------------------\n");
	i = 0;
	while (pipex->cmd_arg_str[i])
	{
		dprintf(2, "cmd_tab %s\n", pipex->cmd_arg_str[i]);
		i++;
	}
	pipex->cmd_str = get_cmd(pipex->cmd_paths, pipex->cmd_arg_str[0]);
	dprintf(2, "\ncmd_str : %s\n", pipex->cmd_str);
	if (!pipex->cmd_str)
		free_error_cmd(pipex);
	if (!execve(pipex->cmd_str, pipex->cmd_arg_str, envp))
		free_error_cmd(pipex);
}

void	second_child(t_pipex *pipex, char *argv[], char *envp[])
{
	dup2(pipex->tube[0], 0);
	close(pipex->tube[1]);
	dup2(pipex->outfile, 1);
	pipex->cmd_arg_str = ft_split(argv[3], ' ');
	pipex->cmd_str = get_cmd(pipex->cmd_paths, pipex->cmd_arg_str[0]);
	if (!pipex->cmd_str)
		free_error_cmd(pipex);
	if (!execve(pipex->cmd_str, pipex->cmd_arg_str, envp))
		free_error_cmd(pipex);
}
