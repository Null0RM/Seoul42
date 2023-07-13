/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:32:27 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/17 19:47:01 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (flag == 1)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			flag = 0;
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] == s2[i])
		{
			i++;
			continue ;
		}
		i++;
	}
	return (0);
}
