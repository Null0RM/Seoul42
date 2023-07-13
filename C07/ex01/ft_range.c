/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:26:23 by hyojung           #+#    #+#             */
/*   Updated: 2023/02/02 04:15:05 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	numcopy(int *num_arr, int min, int max)
{
	long long	tmp;

	tmp = min;
	while (tmp < max)
	{	
		num_arr[tmp - min] = tmp;
		tmp++;
	}
}

int	*ft_range(int min, int max)
{
	long long	size;
	int			*num_arr;

	size = max - min;
	if (size <= 0)
		return (NULL);
	num_arr = (int *)malloc(sizeof(int) * size);
	numcopy(num_arr, min, max);
	return (num_arr);
}
