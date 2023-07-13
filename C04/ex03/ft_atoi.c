/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:43:17 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/31 16:34:06 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ck_start_point(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	check_sign_and_num(char *str, int start_point, int *sign)
{
	int	i;
	int	minus;

	i = 0;
	minus = 0;
	while (str[start_point + i] == '+' || str[start_point + i] == '-')
	{
		if (str[start_point + i] == '-')
			minus++;
		i++;
	}
	if (minus % 2 == 0)
		*sign = 0;
	else
		*sign = 1;
	return (i + start_point);
}

int	num_size(char *str, int num_start_point)
{
	int	i;

	i = 0;
	while (str[num_start_point + i] >= '0'
		&& str[num_start_point + i] <= '9')
		i++;
	return (i);
}

int	set_num(char *str, int num_start_point, int num_size)
{
	int	i;
	int	weight;
	int	result;

	result = 0;
	i = 0;
	weight = 1;
	while (i < num_size)
	{
		result += (str[num_start_point + num_size - i - 1] - '0') * weight;
		weight *= 10;
		i++;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int				start_point;
	int				num_start_point;
	int				size;
	int				sign;
	unsigned int	result;

	result = 0;
	start_point = ck_start_point(str);
	num_start_point = check_sign_and_num(str, start_point, &sign);
	size = num_size(str, num_start_point);
	result = set_num(str, num_start_point, size);
	if (sign == 0)
		return (result);
	else
	{
		if (result == 2147483848)
			return (-2147483648);
		else
			return (-result);
	}
	return (0);
}
