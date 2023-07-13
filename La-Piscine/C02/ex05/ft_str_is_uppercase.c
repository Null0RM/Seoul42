/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:29:14 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/18 12:25:19 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
{
	int	check_i;

	check_i = 0;
	while (str[check_i] != '\0')
	{
		if (str[check_i] < 'A' || str[check_i] > 'Z')
			return (0);
		check_i++;
	}
	return (1);
}
