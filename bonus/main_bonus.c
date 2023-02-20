/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:26:44 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/20 18:42:52 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_ppxb	*pipex;

	pipex = malloc(sizeof(t_ppxb));
	if (!pipex)
		msg_error(ERR_MALLOC, pipex);
	if (argc < args_in(argv[1], pipex))
		msg_error(ERR_INPUT, pipex);
	if (!find_path_set(envp, "PATH"))
		msg_error(ERR_PATH_UNSET, pipex);
	get_infile(argv, pipex);
	get_outfile(argv[argc - 1], pipex);

	free(pipex);
	return (0);
}
