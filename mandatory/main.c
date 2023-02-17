/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:01:03 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/17 15:15:44 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

void	ft_pipex(t_pipex *pipex, char *argv[], char *envp[])
{
	if (pipe(pipex->tube) < 0)
		msg_error(ERR_PIPE);
	pipex->path_env = find_path(envp);
	pipex->cmd_paths = ft_split(pipex->path_env, ':');
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		msg_error(ERR_FORK);
	else if (pipex->pid1 == 0)
		first_child(pipex, argv, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		msg_error(ERR_FORK);
	else if (pipex->pid2 == 0)
		second_child(pipex, argv, envp);
	close_pipes(pipex);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	free_parent(pipex);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc != 5)
		return (msg(ERR_INPUT));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		msg_error(ERR_INFILE);
	pipex.outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.outfile < 0)
		msg_error(ERR_OUTFILE);
	ft_pipex(&pipex, argv, envp);
	return (0);
}
