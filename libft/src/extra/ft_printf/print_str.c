/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:45:37 by nibenoit          #+#    #+#             */
/*   Updated: 2022/12/05 13:41:46 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "buffer.h"

void	print_str(const char *str)
{
	int	len;

	if (!str)
	{
		write_buf("(null)", 6);
		return ;
	}
	len = ft_strlen(str);
	write_buf(str, len);
	return ;
}
