/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:08:08 by hyojung           #+#    #+#             */
/*   Updated: 2023/09/03 15:36:59 by hyojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	idx;
	int fd[10];
	char *ret;

	idx = 0;
	while (++idx < argc)
	{
		fd[idx] = open(argv[idx], O_RDONLY);
		do {
			ret = get_next_line(fd[idx]);
			if (!ret)
				break;
			printf("%s", ret);
			close(fd[idx]);
		} while (ret > 0);
	}
	printf("%s", get_next_line(fd[1]));
}
