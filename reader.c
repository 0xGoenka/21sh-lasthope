/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:54:36 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/18 17:18:13 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "header.h"
int		main()
{
	int fd;
	char *s;
	def_term();

	while (42)
	{
		tputs(tgetstr("cl",0), 0, outc);
		fd = open("debug.txt", O_RDONLY);

		while (get_next_line(fd, &s))
		{
			ft_putendl_fd(s, 2);
		}
		close(fd);
		usleep(20000);
	}
	return (0);
}
