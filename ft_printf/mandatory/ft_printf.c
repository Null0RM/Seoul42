/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:32:36 by hyojung           #+#    #+#             */
/*   Updated: 2023/07/13 21:04:49 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (!ft_strncmp(format, "%c", 2))
			ft_format_c(&format, &ap, &len);
		else if (!ft_strncmp(format, "%s", 2))
			ft_format_s(&format, &ap, &len);
		else if (!ft_strncmp(format, "%p", 2))
			ft_format_p(&format, &ap, &len);
		else if (!ft_strncmp(format, "%d", 2) || !ft_strncmp(format, "%i", 2)
			|| !ft_strncmp(format, "%u", 2))
			ft_format_diu(&format, &ap, &len);
		else if (!ft_strncmp(format, "%x", 2) || !ft_strncmp(format, "%X", 2))
			ft_format_hex(&format, &ap, &len);
		else
			ft_format_percent(&format, &len);
	}
	va_end(ap);
	return (len);
}
