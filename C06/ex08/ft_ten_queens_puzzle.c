/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:20:25 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/23 11:47:32 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	print_res(int *array)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = array[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	promising(int cdx, int *array)
{
	int	i;

	i = 0;
	while (i < cdx)
	{
		if (array[cdx] == array[i]
			|| cdx - i == abs(array[cdx] - array[i]))
			return (0);
		i++;
	}
	return (1);
}

void	nqueen(int cdx, int *array, int *count)
{
	int	i;

	i = 0;
	if (cdx == 10)
	{
		print_res(array);
		*count = *count + 1;
		return ;
	}
	while (i < 10)
	{
		array[cdx] = i;
		if (promising(cdx, array))
			nqueen(cdx + 1, array, count);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	array[10];
	int	count;

	count = 0;
	nqueen(0, array, &count);
	return (count);
}
