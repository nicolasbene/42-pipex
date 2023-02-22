/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:41:15 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/22 12:27:41 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/pipex_bonus.h"

// void	free_parent(t_ppxb *pipex)
// {
// 	int	i;

// 	i = 0;
// 	close(pipex->infile);
// 	close(pipex->outfile);
// 	if (pipex->here_doc)
// 		unlink(".heredoc_tmp");
// 	while (pipex->cmd_paths[i])
// 	{
// 		free(pipex->cmd_paths[i]);
// 		i++;
// 	}
// 	free(pipex->cmd_paths);
// }

// void	free_child(t_ppxb *pipex)
// {
// 	int	i;

// 	i = 0;
// 	while (pipex->cmd_arg_str[i])
// 	{
// 		free(pipex->cmd_arg_str[i]);
// 		i++;
// 	}
// 	free(pipex->cmd_arg_str);
// 	free(pipex->cmd_str);
// }

// void	pipe_free(char *msg, t_ppxb *pipex)
// {
// 	close(pipex->infile);
// 	close(pipex->outfile);
// 	if (pipex->here_doc)
// 		unlink(".heredoc_tmp");
// 	msg_error(msg, pipex);
// 	exit(1);
// }

// void	free_error_cmd(t_ppxb *pipex)
// {
// 	free_child(pipex);
// 	msg_error(ERR_CMD, pipex);
// 	exit(1);
// }
