/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:41:26 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/15 13:44:34 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	first_sec(int number, int for_second);
void	second_sec(int for_first, int number);

void	ft_print_comb2(void)
{
	int	num;

	num = 99;
	while (num >= 1)
	{
		first_sec(num, 99 - num + 1);
		num--;
	}
}

void	first_sec(int number, int for_second)
{
	int	array[5];

	array[0] = 99 - number;
	array[1] = array[0] / 10 + '0';
	array[2] = array[0] % 10 + '0';
	array[3] = ' ';
	write(1, &array[1], 1);
	write(1, &array[2], 1);
	write(1, &array[3], 1);
	second_sec(number, for_second);
}

void	second_sec(int for_first, int number)
{
	int	array[4];

	array[0] = number / 10 + '0';
	array[1] = number % 10 + '0';
	array[2] = ',';
	array[3] = ' ';
	write(1, &array[0], 1);
	write(1, &array[1], 1);
	if (number < 99)
	{
		write(1, &array[2], 1);
		write(1, &array[3], 1);
		first_sec(for_first, number + 1);
	}
	else
	{
		if (99 - for_first + number < 197)
		{
			write(1, &array[2], 1);
			write(1, &array[3], 1);
		}
		return ;
	}
}
