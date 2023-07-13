/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:32:44 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/16 15:58:28 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	mainfunc(int val, int idx, int n, char *str);
void	ft_print_combn(int n);

void	mainfunc(int val, int idx, int n, char *str)
{
	int	i;

	i = 0;
	if (n == idx)
	{
		while (i < n)
		{
			write(1, &str[i], 1);
			i++;
		}
		if (str[0] != 10 - n + '0')
		{
			write(1, ", ", 2);
		}
	}
	else
	{
		while (10 > val)
		{
			str[idx] = val + '0';
			mainfunc(val + 1, idx + 1, n, str);
			val++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	str[10];

	mainfunc(0, 0, n, str);
}
