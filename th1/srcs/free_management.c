/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:18:57 by nwyseur           #+#    #+#             */
/*   Updated: 2023/02/20 10:26:48 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_freedbltab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_freecmderr(char *cmd1, char **cmd, t_pipex *pipex)
{
	free(cmd1);
	ft_freedbltab(cmd);
	ft_freedbltab(pipex->path);
}