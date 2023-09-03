/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:10:56 by hyojung           #+#    #+#             */
/*   Updated: 2023/05/04 22:37:19 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;

	if (!dstsize)
		return (ft_strlen(src));
	ret = ft_strlen(dst) + ft_strlen(src);
	while (--dstsize && *dst)
		dst++;
	if (!dstsize)
		return (ret - ft_strlen(dst + 1));
	while (dstsize-- && *src)
		*(dst++) = *(src++);
	*dst = 0;
	return (ret);
}
