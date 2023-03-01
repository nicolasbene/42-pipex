/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:04:15 by nibenoit          #+#    #+#             */
/*   Updated: 2023/03/01 12:20:56 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_cmd(char **cmd_paths, char **cmd_tab)
{
	char	*tmp;
	char	*command;

	while (*cmd_paths)
	{
		tmp = ft_strjoin(*cmd_paths, "/");
		command = ft_strjoin(tmp, cmd_tab[0]);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		cmd_paths++;
	}
	return (NULL);
}

void	ft_execute(char *cmd, char **envp, int *fileout)
{
	char	*env_path;
	char	**cmd_paths;
	char	**cmd_tab;
	char	*cmd_str;

	cmd_tab = ft_split(cmd, ' ');
	if (ft_nopath(cmd_tab, envp, fileout) == 1)
	{
		execve(cmd_tab[0], cmd_tab, envp);
		ft_free_tab(cmd_tab);
		msg_error_closefd_1(fileout);
	}
	env_path = find_path(envp);
	cmd_paths = ft_split(env_path, ':');
	cmd_str = get_cmd(cmd_paths, cmd_tab);
	if (!cmd_str)
	{
		ft_free_cmd_error(cmd_paths, cmd_tab);
		msg_error_closefd_1(fileout);
	}
	execve(cmd_str, cmd_tab, envp);
	ft_free_cmd_error(cmd_paths, cmd_tab);
	msg_error_closefd_1(fileout);
}
