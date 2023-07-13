/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:09:41 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/18 09:12:29 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	char	*str_pos;
	char	*tf_pos;

	if (to_find[0] == '\0')
		return ((char *)str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			str_pos = str + 1;
			tf_pos = to_find + 1;
			while ((*str_pos != '\0' && *tf_pos != '\0') && *str_pos == *tf_pos)
			{
				str_pos++;
				tf_pos++;
			}
			if (*tf_pos == '\0')
				return ((char *)str);
			else if (*str_pos == '\0')
				break ;
		}
		str++;
	}
	return (0);
}
