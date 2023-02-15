/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:47:12 by nibenoit          #+#    #+#             */
/*   Updated: 2022/12/05 13:33:07 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

# include <stdarg.h>

void	print_char(unsigned char c);
void	print_str(const char *s);
void	print_decimal(int i);
void	print_uint(unsigned int u);
void	print_ptr(void *p);
void	print_hex(int i, char *str);

void	print_uint_base(unsigned long int val, const char *base);

#endif