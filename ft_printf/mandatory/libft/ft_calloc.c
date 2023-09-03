/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:36:06 by hyojung           #+#    #+#             */
/*   Updated: 2023/05/05 06:25:17 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;

	tmp = malloc(count * size);
	if (!tmp)
		return (0);
	ft_memset(tmp, 0, count * size);
	return (tmp);
}
