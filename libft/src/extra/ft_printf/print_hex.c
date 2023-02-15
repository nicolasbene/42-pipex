/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:20:48 by nibenoit          #+#    #+#             */
/*   Updated: 2022/12/05 11:52:18 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"
#include "bases.h"

void	print_hex(int hex, char *str)
{
	if (*str == 'X')
		print_uint_base((unsigned int)hex, BASE_16_UP);
	else
		print_uint_base((unsigned int)hex, BASE_16_LOW);
}
