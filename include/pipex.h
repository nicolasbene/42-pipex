/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:03:09 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/16 19:16:12 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// to write, read, close, access, pipe, dup, dup2, execve, fork
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

# include <sys/wait.h>

# include <fcntl.h>
# include <stdio.h>

# include "libft.h"

# define ERR_INFILE "Infile Erro"
# define ERR_OUTFILE "Outfile Error"
# define ERR_INPUT "Input Error"
# define ERR_PIPE "Pipe Error"
# define ERR_FORK "Fork Error"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*path_env;
	char	**cmd_paths;
	char	**cmd_arg_str;
	char	*cmd_str;
}t_pipex;

void	msg_error(char *err);
int		msg(char *err);

void	first_child(t_pipex *pipex, char *argv[], char *envp[]);
void	second_child(t_pipex *pipex, char *argv[], char *envp[]);

void	free_parent(t_pipex *pipex);

#endif