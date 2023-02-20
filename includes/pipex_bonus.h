/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:45:28 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/20 18:38:42 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

# define ERR_INFILE "Infile Error"
# define ERR_OUTFILE "Outfile Error"
# define ERR_INPUT "Invalid number of arguments"
# define ERR_PATH_UNSET "Unset Path Error"
# define ERR_PIPE "Pipe Error"
# define ERR_FORK "Fork Error"
# define ERR_CMD "Command not found:"
# define ERR_EXECVE "Execve Error"
# define ERR_HEREDOC "here_doc Error"
# define ERR_MALLOC "Malloc Error"

typedef struct s_ppxb
{
	pid_t	pid;
	int		infile;
	int		outfile;
	char	*env_path;
	char	**cmd_paths;
	char	**cmd_arg_str;
	char	*cmd_str;
	int		here_doc;
	int		cmd_nmbs;
	int		pipe_nmbs;
	int		*pipe;
	int		index;
}	t_ppxb;

/* files_bonus.c */
char	*find_path(char **envp);
int		find_path_set(char **envp, char *path);
void	get_infile(char **argv, t_ppxb *pipex);
void	get_outfile(char *argv, t_ppxb *pipex);

/* here_doc_bonus.c */
int		args_in(char *arg, t_ppxb *pipex);
void	here_doc(char *argv, t_ppxb *pipex);

/* error_bonus.c */
void	msg_error(char *err, t_ppxb *pipex);

/* funcions */
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);

#endif