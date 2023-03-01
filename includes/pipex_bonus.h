/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:45:28 by nibenoit          #+#    #+#             */
/*   Updated: 2023/03/01 14:37:40 by nibenoit         ###   ########.fr       */
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

# define STDIN_FILENO 0
# define STDOUT_FILENO 1

/* Variables for the pipes */
# define READ_END	0
# define WRITE_END	1

/* paths_bonus.c */
char	*find_path(char **envp);
int		find_path_set(char **envp, char *path);
int		ft_nopath(char **cmd_tab, char **envp, int *fileout);

/* here_doc_bonus.c */
int		here_doc(char *limiter, int *fileout);

/* execute_bonus.c */
void	ft_execute(char *argv, char **envp, int *fileout);
char	*get_cmd(char **cmd_paths, char **cmd_tab);

/* error_bonus.c */
void	msg_error(void);
void	msg_error_closefd_1(int *file);
void	msg_error_closefd_2(int *file, int *file1);
void	msg_error_closefd_3(int *file, int *file1, int *file2);
void	msg_error_closefd_4(int *file, int *file1, int *file2, int *file3);
void	arg_error(void);

/* free_bonus.c */
void	ft_free_cmd_error(char **cmd_paths, char **cmd_tab);
void	ft_free_tab(char **tab);

/* close_bonus.c */

/* funcions */
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *str, int c);

#endif