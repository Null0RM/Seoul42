/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 02:02:44 by hyojung           #+#    #+#             */
/*   Updated: 2023/07/13 21:54:35 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_c(const char **format, va_list *ap, size_t *len)
{
	char	var;

	var = va_arg(*ap, int);
	write(1, &var, 1);
	*len += 1;
	*format += 2;
}

void	ft_format_s(const char **format, va_list *ap, size_t *len)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		*len += 6;
	}
	else
	{
		write(1, str, ft_strlen(str));
		*len += ft_strlen(str);
	}
	*format += 2;
}

void	ft_format_p(const char **format, va_list *ap, size_t *len)
{
	unsigned long	val;

	val = (unsigned long)va_arg(*ap, void *);
	write(1, "0x", 2);
	if (!val)
		write(1, "0", 1);
	else
		ft_hex_conv(0, val, len);
	*len += 2 + (!val);
	*format += 2;
}

void	ft_format_diu(const char **format, va_list *ap, size_t *len)
{
	char	*str;

	if (!ft_strncmp(*format, "%d", 2) || !ft_strncmp(*format, "%i", 2))
		str = ft_itoa(va_arg(*ap, int));
	else
		str = ft_itoa_unsigned(va_arg(*ap, unsigned int));
	write(1, str, ft_strlen(str));
	*len += ft_strlen(str);
	free(str);
	*format += 2;
}

void	ft_format_hex(const char **format, va_list *ap, size_t *len)
{
	unsigned int	val;

	val = va_arg(*ap, unsigned int);
	if (!val)
		write(1, "0", 1);
	else if (!ft_strncmp(*format, "%x", 2))
		ft_hex_conv(0, val, len);
	else
		ft_hex_conv(1, val, len);
	*len += (!val);
	*format += 2;
}
