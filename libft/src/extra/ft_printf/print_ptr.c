/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:23:44 by nibenoit          #+#    #+#             */
/*   Updated: 2022/12/05 13:42:55 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "printers.h"
#include "bases.h"

void	print_ptr(void *p)
{
	unsigned long int	uli;

	if (!p)
	{
		write_buf("(nil)", 5);
		return ;
	}
	uli = (unsigned long int)p;
	write_buf("0x", 2);
	print_uint_base(uli, BASE_16_LOW);
}
