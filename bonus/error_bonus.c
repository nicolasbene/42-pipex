/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:57:16 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/22 14:57:58 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	arg_error(void)
{
	ft_putstr_fd("Invalid arguments", 2);
	exit(EXIT_SUCCESS);
}

void	msg_error(int i)
{
	perror("Error");
	printf("%d\n", i);
	exit(EXIT_FAILURE);
}