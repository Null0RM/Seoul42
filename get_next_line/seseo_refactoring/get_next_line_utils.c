/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:51:08 by hyojung           #+#    #+#             */
/*   Updated: 2023/09/03 16:10:56 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	len(int flag, const char *str)
{
	const char	*org;

	org = str;
	if (!str)
		return (0);
	while (*str && ((flag == 2) || !(*str == '\n')))
	{
		if ((*str == '\n') && (flag == 2))
			flag--;
		str++;
	}
	return (str - org + ((flag != 0) && (*str == '\n')));
}

void	lcpy(char *dst, const char *src, size_t dstsize)
{
	if (!dstsize)
		return ;
	while (--dstsize && *src)
		*(dst++) = *(src++);
	*dst = 0;
}
