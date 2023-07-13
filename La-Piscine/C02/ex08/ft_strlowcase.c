/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:14:03 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/18 13:27:44 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str);

char	*ft_strlowcase(char *str)
{
	int	count_i;

	count_i = 0;
	while (str[count_i] != '\0')
	{
		if (str[count_i] >= 'A' && str[count_i] <= 'Z')
			str[count_i] += 32;
		count_i++;
	}
	return (str);
}
