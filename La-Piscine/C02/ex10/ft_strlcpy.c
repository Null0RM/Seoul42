/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:07:09 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/18 13:25:48 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_size(char *src)
{
	int	i;

	i = 0;
	while ((*(src + i) != '\0'))
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while ((*(src + i) != '\0') && (i + 1 < size))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	if (size >= 1)
	{
		*(dest + i) = '\0';
	}
	return (get_size(src));
}
