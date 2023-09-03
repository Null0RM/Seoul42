/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:18:02 by hyojung           #+#    #+#             */
/*   Updated: 2023/05/04 22:51:07 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*ret;

	ret = (char *)src;
	if (!dstsize)
		return (ft_strlen(src));
	while (*src && --dstsize)
		*(dst++) = *(src++);
	*dst = 0;
	return (ft_strlen(ret));
}
