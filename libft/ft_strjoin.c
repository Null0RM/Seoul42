/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 06:45:23 by hyojung           #+#    #+#             */
/*   Updated: 2023/05/16 10:01:02 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*add;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	add = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!add)
		return (NULL);
	ret = add;
	while (len1--)
		*(add++) = *(s1++);
	while (len2--)
		*(add++) = *(s2++);
	*(add) = 0;
	return (ret);
}
