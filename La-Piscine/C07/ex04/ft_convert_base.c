/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:41:27 by hyojung           #+#    #+#             */
/*   Updated: 2023/02/02 04:15:03 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		base_valid(char *base);
char	*ft_zero_string(char *base_to);

int	ft_char_idx_in_base(char ch, const char *base)
{
	int	i;

	i = 1;
	while (base[i - 1])
	{
		if (base[i - 1] == ch)
			return (i);
		i++;
	}
	return (0);
}

long long	ft_make_result(char *nbr, char *base, int base_len)
{
	long long	result;
	int			i;

	result = 0;
	i = ft_char_idx_in_base(*nbr, base);
	while (i)
	{
		result *= base_len;
		result += i - 1;
		nbr++;
		i = ft_char_idx_in_base(*nbr, base);
	}
	return (result);
}

char	*ft_putnbr_base(long long lnb, char *base, int base_len, int sign)
{
	int			i;
	int			j;
	char		stack[50];
	char		*string;

	i = 0;
	while (lnb)
	{
		stack[i++] = base[lnb % base_len];
		lnb = lnb / base_len;
	}
	string = malloc(sizeof(*string) * (i + 1));
	i--;
	string[0] = '-';
	j = 1;
	while (i >= 0)
	{
		string[j] = stack[i];
		j++;
		i--;
	}
	string[j] = '\0';
	if (sign == 1)
		string++;
	return (string);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	lnb;
	int			sign;
	int			base_len[2];
	char		*string;

	base_len[0] = base_valid(base_from);
	base_len[1] = base_valid(base_to);
	if (!base_len[0] || !base_len[1])
		return (NULL);
	while (((*nbr) >= 9 && (*nbr) <= 13) || (*nbr) == ' ')
		nbr++;
	sign = 1;
	while ((*nbr) == '+' || (*nbr) == '-')
	{
		if ((*nbr) == '-')
			sign *= -1;
		nbr++;
	}
	lnb = ft_make_result(nbr, base_from, base_len[0]);
	if (lnb == 0)
		return (ft_zero_string(base_to));
	string = ft_putnbr_base(lnb, base_to, base_len[1], sign);
	return (string);
}
