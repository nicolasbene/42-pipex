/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:01:03 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/15 17:42:25 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int main(int argc, char *argv[], char *envp[]) 
{
    t_pipex pipex;

    if (argc != 5)
        return (msg(ERR_INPUT));
    pipex.infile = open(argv[1], O_RDONLY);
    if (pipex.infile < 0)
        msg_error(ERR_INFILE);
    pipex.outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR);
    if (pipex.outfile < 0)
        msg_error(ERR_OUTFILE);
    if (pipe(pipex.tube) < 0)
		msg_error(ERR_PIPE);
    pipex.paths = find_path(envp);
    pipex.cmd_paths = ft_split(pipex.paths, ':');
    pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, argv, envp);
    pipex.pid2 = fork();
    if (pipex.pid2 == 0)
        second_child(pipex, argv, envp);
    return 0;
}
