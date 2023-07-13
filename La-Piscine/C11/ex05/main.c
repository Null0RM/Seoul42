/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:29:02 by hyojung           #+#    #+#             */
/*   Updated: 2023/02/01 09:07:43 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	sum(int a, int b);
int	sub(int a, int b);
int	mul(int a, int b);
int	div(int a, int b);
int	mod(int a, int b);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *num)
{
	int	res;
	int	i;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	while (num[i] == ' '
		|| (num[i] >= 9 && num[i] <= 13))
		i++;
	while (num[i] == '+' || num[i] == '-')
		if (num[i++] == '-')
			sign = sign * (-1);
	while (num[i] >= '0' && num[i] <= '9')
	{
		res = res * 10 + num[i] - '0';
		i++;
	}
	return (sign * res);
}

int	check_sign(char *c)
{
	if (ft_strlen(c) != 1)
		return (0);
	else if (c[0] == '+')
		return (1);
	else if (c[0] == '-')
		return (2);
	else if (c[0] == '*')
		return (3);
	else if (c[0] == '/')
		return (4);
	else if (c[0] == '%')
		return (5);
	return (0);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	oper;
	int	(*f[5])(int, int);

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	oper = check_sign(argv[2]);
	if (oper == 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	f[0] = sum;
	f[1] = sub;
	f[2] = mul;
	f[3] = div;
	f[4] = mod;
	f[oper - 1](a, b);
	write(1, "\n", 1);
	return (0);
}
