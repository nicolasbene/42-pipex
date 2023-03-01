/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:53:20 by nibenoit          #+#    #+#             */
/*   Updated: 2023/03/01 14:10:26 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	return (*envp + 5);
}

int	find_path_set(char **envp, char *path)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], path, 4))
			return (1);
		i++;
	}
	return (0);
}

int	ft_nopath(char **cmd_tab, char **envp, int *fileout)
{
	if (!find_path_set(envp, "PATH"))
	{
		if (ft_strchr(cmd_tab[0], '/'))
		{
			if (access(cmd_tab[0], F_OK) == 0)
				return (1);
		}
		ft_free_tab(cmd_tab);
		msg_error_closefd_1(fileout);
	}
	else if (ft_strchr(cmd_tab[0], '/'))
	{
		if (access(cmd_tab[0], F_OK) == 0)
			return (1);
		ft_free_tab(cmd_tab);
		msg_error_closefd_1(fileout);
	}
	return (0);
}
