/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:03:09 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/17 15:12:50 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* to write, read, close, access, pipe, dup, dup2, execve, fork*/
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* waitpid, wait */
# include <sys/wait.h>

/* open, unlink */
# include <fcntl.h>

/*to perror*/
# include <stdio.h>

/* to get_next_line */
# include "../gnl/get_next_line.h"

# define ERR_INFILE "Infile Erro"
# define ERR_OUTFILE "Outfile Error"
# define ERR_INPUT "Input Error"
# define ERR_PIPE "Pipe Error"
# define ERR_FORK "Fork Error"
# define ERR_CMD "Command not found"

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

/* childs.c */
void	first_child(t_pipex *pipex, char *argv[], char *envp[]);
void	second_child(t_pipex *pipex, char *argv[], char *envp[]);

/* error.c */
void	msg_error(char *err);
int		msg(char *err);

/* free.c */
void	free_parent(t_pipex *pipex);
void	free_child(t_pipex *pipex);

/* funcions */
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);

#endif