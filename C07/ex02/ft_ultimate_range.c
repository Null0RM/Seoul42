/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:44:40 by hyojung           #+#    #+#             */
/*   Updated: 2023/02/02 04:15:05 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	size;
	long long	i;
	int			*tmp;

	if (min >= max)
	{
		return (0);
	}
	size = (long long)max - (long long)min;
	tmp = malloc(sizeof(int) * (size));
	if (!tmp)
		return (-1);
	i = min;
	*range = tmp;
	while (i - min < size)
	{
		tmp[i - min] = i;
		i++;
	}
	return (size);
}
