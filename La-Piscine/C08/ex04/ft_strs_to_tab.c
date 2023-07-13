/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 07:06:39 by hyojung           #+#    #+#             */
/*   Updated: 2023/01/30 22:16:28 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		size;

	size = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * size + 1);
	ft_strcpy(dest, src);
	if (!dest)
		return (NULL);
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*forms;

	i = 0;
	forms = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!forms)
		return (0);
	while (i < ac)
	{
		forms[i].size = ft_strlen(av[i]);
		forms[i].str = av[i];
		forms[i].copy = ft_strdup(av[i]);
		i++;
	}
	forms[i].str = (char *)0;
	return (forms);
}
