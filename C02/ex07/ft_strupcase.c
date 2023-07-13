/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:37:16 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/18 09:37:19 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str);

char	*ft_strupcase(char *str)
{
	int	count_i;

	count_i = 0;
	while (str[count_i] != '\0')
	{
		if (str[count_i] >= 'a' && str[count_i] <= 'z')
			str[count_i] -= 32;
		count_i++;
	}
	return (str);
}
