/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:50:57 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/13 15:51:11 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char		*get_next_line(int fd);
char		*ft_getres(char *res, char *buff);
char		*ft_read_file(int fd, char *buff);
char		*ft_strjfree(char *buff, char *buff2);
char		*ft_strjoin_g(char *buff, char *buff2);
size_t		ft_strlen_g(char *str);
char		*ft_nextline(char *buff, char *res);
char		*ft_getline(char *buff);
int			ft_strchr_g(char *str, char c);
int			has_newline(char *s);

#endif
