/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:26:44 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/23 15:47:05 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	child_process(char *cmd, char **envp, int *fileprev)
{
	pid_t	pid;
	int		p[2];

	if (pipe(p) == -1)
		msg_error(4);
	pid = fork();
	if (pid == -1)
		msg_error(5);
	if (pid == 0)
	{
		close(p[READ_END]);
		if (dup2(*fileprev, STDIN_FILENO) < 0)
			msg_error(100);
		close(*fileprev);
		if (dup2(p[WRITE_END], STDOUT_FILENO) < 0)
			msg_error(200);
		ft_execute(cmd, envp);
	}
	close(*fileprev);
	*fileprev = p[READ_END];
	close(p[WRITE_END]);
}

void	last_child_process(char *cmd, char **envp, int *fileprev, int fileout)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		msg_error(8);
	if (pid == 0)
	{
		if (dup2(*fileprev, STDIN_FILENO) < 0)
			msg_error(22);
		close(*fileprev);
		if (dup2(fileout, STDOUT_FILENO) < 0)
			msg_error(23);
		close(fileout);
		ft_execute(cmd, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	filein;
	int	fileout;
	int	fileprev;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			fileout = open_file(argv[argc - 1], 0);
			filein = here_doc(argv[2]);
		}
		else
		{
			i = 2;
			fileout = open_file(argv[argc - 1], 1);
			filein = open_file(argv[1], 2);
		}
		fileprev = filein;
		while (i < argc - 2)
		{
			child_process(argv[i], envp, &fileprev);
			i++;
		}
		last_child_process(argv[argc - 2], envp, &fileprev, fileout);
	}
	waitpid(-1, NULL, 0);
	return (0);
}
