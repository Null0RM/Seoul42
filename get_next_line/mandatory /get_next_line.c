/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:51:12 by hyojung           #+#    #+#             */
/*   Updated: 2023/09/04 01:41:16 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_fd	*t_list = NULL;
	t_fd		*c_list;
	char		*line;
	int			stat;

	c_list = get_list(fd, &t_list);
	if (!c_list)
		return (NULL);
	line = get_ret(0, NULL, c_list);
	while (len(0, line) == len(1, line))
	{
		stat = read(fd, c_list->buf, BUFFER_SIZE);
		if (stat <= 0)
			return (get_freed(stat, line, &t_list, c_list));
		c_list->buf[stat] = 0;
		line = get_ret(1, line, c_list);
		if ((len(0, c_list->buf) != len(1, c_list->buf))
			&& len(1, c_list->buf) != BUFFER_SIZE)
			break ;
	}
	return (line);
}

char	*get_ret(int flag, char *line, t_fd *c_list)
{
	char	*tmp;
	size_t	size;

	if (flag == 0 && (c_list->buf[0]) && (len(1, c_list->buf) < BUFFER_SIZE))
	{
		size = len(2, c_list->buf) - len(1, c_list->buf) + 1;
		if (size == 1)
			return (NULL);
		line = (char *)malloc(size);
		if (!line)
			return (NULL);
		lcpy(line, c_list->buf + len(1, c_list->buf), size);
		size = len(1, c_list->buf);
		lcpy(c_list->buf, c_list->buf + size, BUFFER_SIZE - size + 1);
	}
	else if (flag == 1)
	{
		tmp = line;
		size = len(1, line) + len(1, c_list->buf) + 1;
		if (size == 1)
			return (NULL);
		line = (char *)malloc(size);
		if (!line)
		{
			free(tmp);
			return (NULL);
		}
		lcpy(line, tmp, len(1, tmp) + 1);
		lcpy(line + len(1, tmp), c_list->buf, len(1, c_list->buf) + 1);
		free(tmp);
	}
	return (line);
}

char	*get_freed(int flag, char *line, t_fd **t_list, t_fd *c_list)
{
	free(c_list->buf);
	if (*t_list == c_list)
		*t_list = c_list->next;
	else
		c_list->prev->next = c_list->next;
	free(c_list);
	if (line && flag == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

t_fd	*get_list(int fd, t_fd **t_list)
{
	t_fd	*c_list;

	if (!(*t_list))
	{
		*t_list = (t_fd *)malloc(sizeof(t_fd));
		if (!(*t_list))
			return (NULL);
		(*t_list)->next = NULL;
		(*t_list)->prev = NULL;
		return (init_list(0, fd, NULL, *t_list, t_list));
	}
	c_list = *t_list;
	while (1)
	{
		if (c_list->fdisc == fd)
			return (c_list);
		else if (c_list->next == NULL)
			return (init_list(1, fd, c_list, c_list->next, t_list));
		c_list = c_list->next;
	}
}

t_fd	*init_list(int flag, int fd, t_fd *prev, t_fd *c_list, t_fd **t_list)
{
	if (flag == 1)
	{
		c_list = (t_fd *)malloc(sizeof(t_fd));
		if (!c_list)
			return (NULL);
		c_list->next = NULL;
		c_list->prev = NULL;
		prev->next = c_list;
	}
	c_list->fdisc = fd;
	c_list->buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!c_list->buf)
	{
		if (c_list->prev)
			c_list->prev->next = c_list->next;
		if (c_list->next)
			c_list->next->prev = c_list->prev;
		if (c_list == *t_list)
			*t_list = NULL;
		free(c_list);
		return (NULL);
	}
	c_list->buf[0] = 0;
	c_list->prev = prev;
	c_list->next = NULL;
	return (c_list);
}
