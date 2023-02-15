/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:59:13 by nibenoit          #+#    #+#             */
/*   Updated: 2022/12/05 13:42:23 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "buffer.h"

int	write_buf(const char *str, size_t len)
{
	int				tmp;
	static size_t	wrote = 0;

	if (!len && !str)
	{
		tmp = wrote;
		wrote = 0;
		return (tmp);
	}
	wrote += write(1, str, len);
	return (0);
}
