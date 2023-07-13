/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:11:39 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/17 20:23:48 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);
void	spchar_to_hex(unsigned char a);

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			spchar_to_hex((unsigned char)str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}

void	spchar_to_hex(unsigned char a)
{
	write(1, "\\", 1);
	write(1, &"0123456789abcdef"[a / 16], 1);
	write(1, &"0123456789abcdef"[a % 16], 1);
}
