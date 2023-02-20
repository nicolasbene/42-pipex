/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:01:03 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/20 15:50:55 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	find_path_set(char **envp, char *path)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], path, 4))
			return (1);
		i++;
	}
	return (0);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

int	ft_pipex(t_pipex *pipex, char *argv[], char *envp[])
{
	if (pipe(pipex->tube) < 0)
		msg_error(ERR_PIPE, pipex);
	pipex->env_path = find_path(envp);
	pipex->cmd_paths = ft_split(pipex->env_path, ':');
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		msg_error(ERR_FORK, pipex);
	else if (pipex->pid1 == 0)
		first_child(pipex, argv, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		msg_error(ERR_FORK, pipex);
	else if (pipex->pid2 == 0)
		second_child(pipex, argv, envp);
	close_pipes(pipex);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	free_parent(pipex);
	free(pipex);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;

	if (argc != 5)
		return (msg(ERR_INPUT));
	if (!find_path_set(envp, "PATH"))
		return (msg(ERR_PATH_UNSET));
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (msg(ERR_MALLOC));
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		msg_error(ERR_INFILE, pipex);
	pipex->outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->outfile < 0)
		msg_error(ERR_OUTFILE, pipex);
	ft_pipex(pipex, argv, envp);
	return (0);
}
