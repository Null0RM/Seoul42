/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:15:06 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/18 13:02:24 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);
int		pos_check(char c);

char	*ft_strcapitalize(char *str)
{
	int	flag;
	int	i;

	i = -1;
	flag = 1;
	while (str[++i] != '\0')
	{
		if (pos_check(str[i]) == 1 && flag == 1)
		{
			str[i] -= 32;
			flag = 0;
		}
		else if (pos_check(str[i]) == 2)
		{
			if (flag == 1)
				flag = 0;
			else
				str[i] += 32;
		}
		else if (pos_check(str[i]) == 3)
			flag = 0;
		else if (pos_check(str[i]) == 0)
			flag = 1;
	}
	return (str);
}

int	pos_check(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	else if (c >= '0' && c <= '9')
		return (3);
	return (0);
}
