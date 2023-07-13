/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:20:24 by hyojung           #+#    #+#             */
/*   Updated: 2023/02/02 04:15:04 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_size1(int size, char **strs)
{
	int	i;
	int	j;
	int	cnt;

	cnt = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			cnt++;
			j++;
		}
		i++;
	}
	return (cnt - 1);
}

int	check_size2(char *str)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		cnt++;
		i++;
	}
	return (cnt - 1);
}

void	catstr(int size, char *str, char **strs, char *sep)
{
	int	i;
	int	k;
	int	j;

	i = -1;
	k = 0;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j] != '\0')
			str[k++] = strs[i][j];
		j = -1;
		if (i != size - 1)
			while (sep[++j] != '\0')
				str[k++] = sep[j];
	}
	str[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		count1;
	int		count2;

	if (size <= 0)
	{
		str = (char *)malloc(sizeof(char) * 1);
		return (str);
	}
	count1 = check_size1(size, strs);
	count2 = check_size2(sep);
	str = (char *)malloc(count1 * size + count2 * (size - 1) + 1);
	catstr(size, str, strs, sep);
	return (str);
}
