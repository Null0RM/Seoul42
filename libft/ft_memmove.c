/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:25:49 by hyojung           #+#    #+#             */
/*   Updated: 2023/05/04 20:55:34 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*ret;

	ret = dst;
	if (dst < src)
		while (dst != src && len--)
			*((char *)dst++) = *((char *)src++);
	else
		while (dst != src && len--)
			*((char *)dst + len) = *((char *)src + len);
	return (ret);
}
