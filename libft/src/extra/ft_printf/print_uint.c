/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:22:55 by nibenoit          #+#    #+#             */
/*   Updated: 2022/12/01 17:23:45 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"
#include "bases.h"
#include "libft.h"
#include "buffer.h"

void	print_uint_base(unsigned long int val, const char *base)
{
	size_t	len;

	len = ft_strlen(base);
	if (val > len - 1)
	{
		print_uint_base(val / len, base);
		write_buf(base + (val % len), 1);
	}
	else
		write_buf(base + val, 1);
}

void	print_uint(unsigned int u)
{
	print_uint_base(u, BASE_10);
}
