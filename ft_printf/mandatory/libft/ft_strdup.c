/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:36:14 by hyojung           #+#    #+#             */
/*   Updated: 2023/05/16 04:53:01 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	n;
	char	*res;

	i = ft_strlen(s1);
	n = 0;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	while (n < i)
	{
		res[n] = s1[n];
		n++;
	}
	res[n] = 0;
	return (res);
}
