/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:04:15 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/24 14:33:19 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	*get_cmd(char **cmd_paths, char *arg_main)
{
	char	*tmp;
	char	*command;

	while (*cmd_paths)
	{
		tmp = ft_strjoin(*cmd_paths, "/");
		command = ft_strjoin(tmp, arg_main);
		free(tmp);
			dprintf(2, "command : %s\n", command);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		cmd_paths++;
	}
	return (NULL);
}

void	ft_execute(char *argv, char **envp)
{
	char 	*env_path;
	char	**cmd_paths;
	char	**cmd_tab;
	char	*cmd_str;

	env_path = find_path(envp);
	cmd_paths = ft_split(env_path, ':');
	cmd_tab = ft_split(argv, ' ');
	int i = 0;
	dprintf(2, "\n------------cmd_path---------------\n");
	while (cmd_paths[i])
	{
		dprintf(2, "cmd_path : %s\n", cmd_paths[i]);
		i++;
	}
	dprintf(2, "\n------------cmd_tab---------------\n");
	i = 0;
	while (cmd_tab[i])
	{
		dprintf(2, "cmd_tab %s\n", cmd_tab[i]);
		i++;
	}
	dprintf(2, "\n------------cmd_str---------------\n");
	cmd_str = get_cmd(cmd_paths, cmd_tab[0]);
	dprintf(2, "\ncmd_str : %s\n", cmd_str);
	if (!cmd_str)
		exit(1);
	dprintf(2, "lalalallal\n\n");
	if (execve(cmd_str, cmd_tab, envp) < 0)
		msg_error(6);
}
