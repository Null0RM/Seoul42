/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 02:02:42 by hyojung           #+#    #+#             */
/*   Updated: 2023/07/13 22:04:29 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_percent(const char **format, size_t *len)
{
	if (!ft_strncmp(*format, "%%", 2))
		write(1, "%", 1);
	else
		write(1, *format, 1);
	*len += 1;
	*format += 1 + !ft_strncmp(*format, "%%", 2);
}

void	ft_hex_conv(int mode, unsigned long val, size_t *len)
{
	char	ret;

	if (val && mode == 0)
	{
		ret = val % 16;
		ret = (ret < 10) * (ret + '0') + (ret >= 10) * (ret + 'a' - 10);
		ft_hex_conv(0, (val - (val % 16)) / 16, len);
		write(1, &ret, 1);
		(*len)++;
	}
	else if (val && mode == 1)
	{
		ret = val % 16;
		ret = (ret < 10) * (ret + '0') + (ret >= 10) * (ret + 'A' - 10);
		ft_hex_conv(1, (val - (val % 16)) / 16, len);
		write(1, &ret, 1);
		(*len)++;
	}
	else
		return ;
}

char	*ft_itoa_unsigned(unsigned int n)
{
	size_t			len;
	char			*ret;
	unsigned long	val;

	len = 0;
	val = n;
	while (++len && n)
	{
		n /= 10;
		if (!n)
			break ;
	}
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = 0;
	ret[0] = '0';
	while (val)
	{
		ret[--(len)] = val % 10 + '0';
		val /= 10;
	}
	return (ret);
}
