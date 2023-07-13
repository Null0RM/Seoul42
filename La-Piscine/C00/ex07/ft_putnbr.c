/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:01:09 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/16 12:28:59 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	pos_nbr(int nb);
void	neg_nbr(int nb);
void	out_of_bound(void);
void	zero(void);

void	ft_putnbr(int nb)
{
	if (nb > 0)
	{
		pos_nbr(nb);
	}
	else if (nb == 0)
	{
		zero();
	}
	else if (nb == -2147483648)
	{
		out_of_bound();
	}
	else
	{
		neg_nbr(-nb);
	}
}

void	pos_nbr(int pos_nb)
{
	int	array[10];
	int	i;
	int	j;
	int	count;

	i = pos_nb;
	j = 0;
	count = 0;
	while (i >= 1)
	{
		array[j] = i % 10;
		i = i / 10;
		j++;
		count++;
	}
	while (count-- > 0)
	{
		i = array[count] + '0';
		write(1, &i, 1);
	}
}

void	neg_nbr(int neg_nb)
{
	int	array[10];
	int	i;
	int	j;
	int	count;
	int	sign;

	sign = '-';
	i = neg_nb;
	j = 0;
	count = 0;
	while (i >= 1)
	{
		array[j] = i % 10;
		i = i / 10;
		j++;
		count++;
	}
	write(1, &sign, 1);
	while (count-- > 0)
	{
		i = array[count] + '0';
		write(1, &i, 1);
	}
}

void	out_of_bound(void)
{
	write(1, "-2147483648", 11);
}

void	zero(void)
{
	write(1, "0", 1);
}
