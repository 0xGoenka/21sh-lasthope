/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:39:14 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/10 16:00:37 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "header.h"

int		debug(t_line *line, int a, int b, int c)
{
	int fd;

	if (!line)
		return (0);
	fd = open("debug.txt", O_WRONLY);
	if (fd == -1)
	{
		ft_putstr("Open error occured\n");
		close(fd);
		return (0);
	}
	dprintf(fd, "pos      ");
	dprintf(fd, "%d \n", line->pos);
	dprintf(fd, "len      ");
	dprintf(fd, "%d \n", line->len);
	dprintf(fd, "col      ");
	dprintf(fd, "%d \n", col());
	dprintf(fd, "int a  : ");
	dprintf(fd, "%d \n",a);
	dprintf(fd, "intb   : ");
	dprintf(fd, "%d \n", b);
	dprintf(fd, " int c : ");
	dprintf(fd, "%d \n", c);
	dprintf(fd, " len ");
	dprintf(fd, " debug str : ");
	dprintf(fd,  "%s                                         ", line->str);
	close(fd);
	return (1);
}
