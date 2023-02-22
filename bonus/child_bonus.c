/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:04:15 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/22 17:59:21 by nibenoit         ###   ########.fr       */
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
	while (*cmd_paths)
	{
		printf("%s\n", *cmd_paths);
		cmd_paths++;		
	}
	cmd_str = get_cmd(envp, cmd_tab[0]);
	printf("%s\n", cmd_str);
	if (execve(cmd_str, cmd_paths, envp) < 0)
		msg_error(6);
}
