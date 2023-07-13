/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:50:39 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/23 11:47:31 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_prime(int nb)
{
	long long	i;
	long long	nbr;

	nbr = nb;
	i = 2;
	if (nbr < 2)
		return (0);
	while (i * i <= nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		nb = 2;
	if (ft_prime(nb))
		return (nb);
	if (nb >= 2147483630 && nb <= 2147483647)
		return (2147483647);
	while (1)
	{
		if (ft_prime(nb))
			return (nb);
		nb++;
	}
	return (0);
}
