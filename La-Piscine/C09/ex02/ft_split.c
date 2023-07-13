/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:31:56 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/31 16:47:32 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != 0)
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	get_word_count(char *str, char *charset)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && check_charset(str[i], charset))
			i++;
		if (str[i])
			cnt++;
		while (str[i] && !check_charset(str[i], charset))
			i++;
	}
	return (cnt);
}

char	*get_word(char *str, char *charset)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = 0;
	while (str[len] && !check_charset(str[len], charset))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		idx;
	char	**res;
	int		word_cnt;

	i = 0;
	idx = 0;
	word_cnt = get_word_count(str, charset);
	res = malloc(sizeof(char *) * (word_cnt + 1));
	while (str[i])
	{
		while (str[i] && check_charset(str[i], charset))
			i++;
		if (str[i])
		{
			res[idx] = get_word(str + i, charset);
			idx++;
		}
		while (str[i] && !check_charset(str[i], charset))
			i++;
	}
	res[idx] = 0;
	return (res);
}
