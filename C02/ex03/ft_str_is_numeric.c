/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:20:50 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/17 18:35:48 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str);

int	ft_str_is_numeric(char *str)
{
	int	check_i;

	check_i = 0;
	while (str[check_i] != '\0')
	{
		if (str[check_i] < '0' || str[check_i] > '9')
		{
			return (0);
		}
		check_i++;
	}
	return (1);
}
