/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:31:28 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/17 18:18:30 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	int	check_i;

	check_i = 0;
	while (str[check_i] != '\0')
	{
		if (str[check_i] <= 31 || str[check_i] >= 127)
		{
			return (0);
		}
		check_i++;
	}
	return (1);
}
