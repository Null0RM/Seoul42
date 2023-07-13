/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:55:54 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/31 23:23:09 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) > 0)
		{
			if (flag == -1)
				return (0);
			flag = 1;
		}
		else if (f(tab[i - 1], tab[i]) < 0)
		{
			if (flag == 1)
				return (0);
			flag = -1;
		}
		i++;
	}
	return (1);
}
