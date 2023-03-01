/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:48:13 by nibenoit          #+#    #+#             */
/*   Updated: 2023/03/01 11:31:45 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	here_doc2(int *fileout)
{
	int	filein;

	filein = open(".heredoc_tmp", O_RDONLY);
	if (filein < 0)
	{
		unlink(".heredoc_tmp");
		msg_error_closefd_1(fileout);
	}
	return (filein);
}

int	here_doc(char *limiter, int *fileout)
{
	char	*line;
	int		filein;

	filein = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (filein < 0)
		msg_error_closefd_1(fileout);
	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		line = get_next_line(0);
		line[ft_strlen(line) - 1] = '\0';
		if (!ft_strncmp(limiter, line, ft_strlen(line)))
			break ;
		write(filein, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(filein);
	filein = here_doc2(fileout);
	close(*fileout);
	unlink(".heredoc_tmp");
	return (filein);
}
