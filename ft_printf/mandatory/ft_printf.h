/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:33:02 by hyojung           #+#    #+#             */
/*   Updated: 2023/07/13 21:54:54 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* __HEADER_START__ */
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
/* __HEADER_END__ */

/* __FUNCTION_START__ */
int		ft_printf(const char *format, ...);

void	ft_format_c(const char **format, va_list *ap, size_t *len);
void	ft_format_s(const char **format, va_list *ap, size_t *len);
void	ft_format_p(const char **format, va_list *ap, size_t *len);
void	ft_format_diu(const char **format, va_list *ap, size_t *len);
void	ft_format_hex(const char **format, va_list *ap, size_t *len);
void	ft_format_percent(const char **format, size_t *len);

void	ft_hex_conv(int mode, unsigned long val, size_t *len);
char	*ft_itoa_unsigned(unsigned int n);
/* __FUNCTION_END__ */

#endif