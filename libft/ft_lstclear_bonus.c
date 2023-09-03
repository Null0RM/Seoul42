/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 05:02:33 by hyojung           #+#    #+#             */
/*   Updated: 2023/05/16 20:11:30 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*add;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		add = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = add;
	}
}
