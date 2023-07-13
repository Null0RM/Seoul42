/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:59:47 by hyojung           #+#    #+#             */
/*   Updated: 2023/02/01 00:23:48 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	check_num(char *base, char ch, int *sum)
{
	int	i;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == ch)
		{
			*sum = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int	sign(char *str, char *base, int len)
{
	int	i;
	int	sum;
	int	count;
	int	result;

	i = 0;
	count = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			count = count * (-1);
	while (check_num(base, str[i], &sum))
	{
		result = result * len + sum;
		i++;
	}
	return (result * count);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	flag;

	result = 0;
	flag = base_valid(base);
	if (flag)
		result = sign(str, base, flag);
	return (result);
}
