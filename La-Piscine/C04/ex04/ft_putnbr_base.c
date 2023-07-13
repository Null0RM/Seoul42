/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:37:36 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/25 21:57:05 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
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

void	print_res(int size, char *base,	int minus, unsigned int result)
{
	char	after_calculate[32];
	int		i;
	int		j;

	i = 0;
	while (result >= (unsigned int)size)
	{
		after_calculate[i] = base[result % size];
		result /= size;
		i++;
	}
	after_calculate[i] = base[result % size];
	if (minus == 1)
		write(1, "-", 1);
	j = i;
	while (j >= 0)
	{
		write(1, &after_calculate[j], 1);
		j--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	result;
	int				minus;
	int				size;

	minus = 0;
	result = nbr;
	size = check_valid_base(base);
	if (size < 2)
		return ;
	if (nbr == -2147483648)
	{
		result = 2147483648;
		minus = 1;
	}
	else if (nbr < 0)
	{
		result = nbr * -1;
		minus = 1;
	}
	print_res(size, base, minus, result);
}
