/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:04:23 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/12 15:01:35 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

void	ft_print_comb(void)
{
	int	array[5];

	array[0] = '0' - 1;
	array[3] = ',';
	array[4] = ' ';
	while (array[0]++ < '7')
	{
		array[1] = array[0];
		while (array[1]++ < '8')
		{
			array[2] = array[1];
			while (array[2]++ < '9')
			{
				write(1, &array[0], 1);
				write(1, &array[1], 1);
				write(1, &array[2], 1);
				if (array[0] != '7')
				{
					write(1, &array[3], 1);
					write(1, &array[4], 1);
				}
			}
		}
	}
}
