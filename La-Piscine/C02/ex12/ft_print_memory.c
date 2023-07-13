/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:25:16 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/31 23:43:56 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	word_column(unsigned char *addr, int start, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (addr[i + start] >= 32 && addr[i + start] <= 126)
			write(1, &addr[i + start], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	hex_column(char *addr, int start, int size)
{
	char	hex[2];
	int		i;

	i = 0;
	while (i < size)
	{
		write(1, &"0123456789abcdef"[addr[i + start] / 16], 1);
		write(1, &"0123456789abcdef"[addr[i + start] % 16], 1);
		write(1, &hex[0], 1);
		write(1, &hex[1], 1);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	addr_column(unsigned long long addr, int size)
{
	if (!size)
	{	
		return ;
	}
	addr_column(addr / 16, size - 1);
	write(1, &"0123456789abcdef"[addr % 16], 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	array[2];

	array[0] = 0;
	array[1] = 0;
	while (array[0] < size - 16 && size >= 16)
	{
		addr_column((long long)addr + array[0], 16);
		write(1, ": ", 2);
		hex_column((char *)addr, array[0], 16);
		word_column((unsigned char *)addr, array[0], 16);
		write(1, "\n", 1);
		array[0] += 16;
	}
	if (size - array[0] > 0)
	{
		addr_column((long long)addr + array[0], 16);
		write(1, ": ", 2);
		hex_column((char *)addr, array[0], size - array[0]);
		while (array[1]++ < (16 - size + array[0])
			* 2 + (17 - size + array[0]) / 2)
			write(1, " ", 1);
		word_column((unsigned char *)addr, array[0], size - array[0]);
		write(1, "\n", 1);
	}
	return (addr);
}
