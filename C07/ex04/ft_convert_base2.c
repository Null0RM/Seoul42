/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:57:38 by hyojung           #+#    #+#             */
/*   Updated: 2023/02/02 04:15:03 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (check_space(base[i]))
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i;
		while (base[++j] != '\0')
			if (base[i] == base[j])
				return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

char	*ft_zero_string(char *base_to)
{
	char	*zero_str;

	zero_str = malloc(sizeof(*zero_str) * 2);
	zero_str[0] = base_to[0];
	zero_str[1] = '\0';
	return (zero_str);
}
