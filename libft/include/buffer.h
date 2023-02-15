/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:51:32 by nibenoit          #+#    #+#             */
/*   Updated: 2022/12/05 11:32:58 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# ifndef PRINTF_BUFFER
#  define PRINTF_BUFFER 400
# endif

# include <stdlib.h>

int	write_buf(const char *str, size_t len);

#endif