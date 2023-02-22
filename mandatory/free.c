/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:43:06 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/21 15:57:35 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_parent(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
}

void	free_child(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_arg_str[i])
	{
		free(pipex->cmd_arg_str[i]);
		i++;
	}
	free(pipex->cmd_arg_str);
	free(pipex->cmd_str);
	free_parent(pipex);
}

void	free_error_cmd(t_pipex *pipex)
{
	free_child(pipex);
	msg_error(ERR_CMD, pipex);
	exit(1);
}
