/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:26:44 by nibenoit          #+#    #+#             */
/*   Updated: 2023/03/01 12:57:31 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0644);
	return (file);
}

void	child_process(char *cmd, char **envp, int *fileprev, int *fileout)
{
	pid_t	pid;
	int		p[2];

	if (pipe(p) == -1)
		msg_error_closefd_2(fileprev, fileout);
	pid = fork();
	if (pid == -1)
		msg_error_closefd_4(fileprev, fileout, &p[0], &p[1]);
	else if (pid == 0)
	{
		if (*fileprev < 0)
			msg_error_closefd_3(fileout, &p[0], &p[1]);
		close(p[READ_END]);
		if (dup2(*fileprev, STDIN_FILENO) < 0)
			msg_error_closefd_3(fileprev, fileout, &p[1]);
		close(*fileprev);
		if (dup2(p[WRITE_END], STDOUT_FILENO) < 0)
			msg_error_closefd_2(fileout, &p[1]);
		close(p[WRITE_END]);
		ft_execute(cmd, envp, fileout);
	}
	close(*fileprev);
	*fileprev = p[READ_END];
	close(p[WRITE_END]);
}

void	last_child_process(char *cmd, char **envp, int *fileprev, int *fileout)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		msg_error_closefd_2(fileprev, fileout);
	else if (pid == 0)
	{
		if (*fileout < 0)
			msg_error_closefd_1(fileprev);
		if (dup2(*fileprev, STDIN_FILENO) < 0)
			msg_error_closefd_2(fileprev, fileout);
		close(*fileprev);
		if (dup2(*fileout, STDOUT_FILENO) < 0)
			msg_error_closefd_1(fileout);
		ft_execute(cmd, envp, fileout);
	}
	close(*fileprev);
	close(*fileout);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	filein;
	int	fileout;

	if (argc == 5)
	{
		i = 2;
		fileout = open_file(argv[argc - 1], 1);
		filein = open_file(argv[1], 2);
		while (i < argc - 2)
			child_process(argv[i++], envp, &filein, &fileout);
		last_child_process(argv[argc - 2], envp, &filein, &fileout);
	}
	while (wait(NULL) != -1)
		;
	return (0);
}
