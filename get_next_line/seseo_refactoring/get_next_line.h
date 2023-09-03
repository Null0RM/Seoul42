/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:51:19 by hyojung           #+#    #+#             */
/*   Updated: 2023/09/04 00:45:36 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* __HEADER_START__ */
# include <stdlib.h>
# include <unistd.h>
/* __HEADER_END__ */

/* __CONST_AND_TYPEDEF_START__ */
typedef struct list_fd
{
	int				fdisc;
	char			*buf;
	struct list_fd	*prev;
	struct list_fd	*next;
}t_fd;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
/* __CONST_AND_TYPEDEF_END__ */

/* __FUNCTION_START__ */
char	*get_next_line(int fd);
char	*get_ret(int flag, char *ret, t_fd *c_list);
char	*get_freed(int flag, char *ret, t_fd **t_list, t_fd *c_list);
t_fd	*get_list(int fd, t_fd **t_list);
t_fd	*init_list(int flag, int fd, t_fd *prev, t_fd *c_list, t_fd **t_list);

size_t	len(int flag, const char *str);
void	lcpy(char *dst, const char *src, size_t dstsize);
/* __FUNCTION_END__ */

#endif