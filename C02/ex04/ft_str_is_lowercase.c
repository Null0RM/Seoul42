/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:26:13 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/17 18:38:32 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
{
	int	check_i;

	check_i = 0;
	while (str[check_i] != '\0')
	{
		if (str[check_i] < 'a' || str[check_i] > 'z')
		{
			return (0);
		}
		check_i++;
	}
	return (1);
}
