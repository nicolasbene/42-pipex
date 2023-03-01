/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:18:06 by nibenoit          #+#    #+#             */
/*   Updated: 2023/03/01 12:58:34 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	msg_error_closefd_1(int *file)
{
	close(*file);
	perror("Error");
	exit(EXIT_FAILURE);
}

void	msg_error_closefd_2(int *file, int *file1)
{
	close(*file);
	close(*file1);
	perror("Error");
	exit(EXIT_FAILURE);
}

void	msg_error_closefd_3(int *file, int *file1, int *file2)
{
	close(*file);
	close(*file1);
	close(*file2);
	perror("Error");
	exit(EXIT_FAILURE);
}

void	msg_error_closefd_4(int *file, int *file1, int *file2, int *file3)
{
	close(*file);
	close(*file1);
	close(*file2);
	close(*file3);
	perror("Error");
	exit(EXIT_FAILURE);
}
