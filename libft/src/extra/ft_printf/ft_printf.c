/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:02:01 by nibenoit          #+#    #+#             */
/*   Updated: 2022/12/05 11:53:06 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printers.h"
#include "buffer.h"

char	*parse_dispatch(char *str, va_list ap)
{
	str++;
	if (*str == '%')
		write_buf("%", 1);
	else if (*str == 'c')
		print_char(va_arg(ap, int));
	else if (*str == 's')
		print_str(va_arg(ap, char *));
	else if (*str == 'p')
		print_ptr(va_arg(ap, void *));
	else if (*str == 'd' || *str == 'i')
		print_decimal(va_arg(ap, int));
	else if (*str == 'u')
		print_uint(va_arg(ap, unsigned int));
	else if (*str == 'x' || *str == 'X')
		print_hex(va_arg(ap, int), str);
	return (str + 1);
}

int	ft_printf(const char *str, ...)
{
	char	*flag_pos;
	va_list	ap;

	va_start(ap, str);
	flag_pos = ft_strchr(str, '%');
	while (flag_pos)
	{
		write_buf(str, flag_pos - str);
		str = parse_dispatch(flag_pos, ap);
		flag_pos = ft_strchr(str, '%');
	}
	write_buf(str, ft_strlen(str));
	va_end(ap);
	return (write_buf(NULL, 0));
}
