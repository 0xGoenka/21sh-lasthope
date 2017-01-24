/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:39:14 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/23 21:06:19 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "header.h"

int		debug(t_line *line, int a, int b, int c)
{
	int fd;
	int i;

	i = 0;
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
	dprintf(fd, " debug buff_copy : ");
	dprintf(fd,  "%s \n", line->buffer_copy);
	dprintf(fd, " debug str : ");
	dprintf(fd,  "%s                                         \n\n", line->str);
	while (i < HLEN)
	{
		if (line->h->tab)
			dprintf(fd, "tab[%d] == %s             \n", i , line->h->tab[i]);
		i++;
	}
	dprintf(fd, "h->pos = %d    h->index = %d     \n", line->h->pos, line->h->index);
	close(fd);
	return (1);
}
