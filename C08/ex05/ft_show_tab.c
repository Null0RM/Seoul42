/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:03:51 by hyojung           #+#    #+#             */
/*   Updated: 2023/02/01 00:57:11 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

void	ft_putnbr(int nb)
{
	char	num[10];
	int		i;

	if (nb == 0)
		write(1, "0", 1);
	i = 0;
	while (nb)
	{
		num[i] = '0' + (nb % 10);
		nb = nb / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &num[i], 1);
		i--;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	len;
	int	i;

	len = 0;
	while (par[len].str)
		len++;
	i = 0;
	while (i < len)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		if (par[i].copy)
			ft_putstr(par[i].copy);
		i++;
	}
}
