/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:53:20 by nibenoit          #+#    #+#             */
/*   Updated: 2022/12/01 17:23:40 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printers.h"
#include "buffer.h"
#include "bases.h"

static void	print_before(int a)
{
	if (a < 0)
		write_buf("-", 1);
}

void	print_decimal(int a)
{
	unsigned int	u;

	if (a < 0)
		u = -a;
	else
		u = a;
	print_before(a);
	print_uint_base(u, BASE_10);
}
