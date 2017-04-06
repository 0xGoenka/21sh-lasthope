/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:54:19 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/06 20:56:56 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			open_file(char *filename, int red_type, int *tfd)
{
	int fd;
	int i;

	i = 0;
	fd = -1;
	if (red_type == 1)
		fd = open(filename, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (red_type == 2)
		fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		return (fd);
	while (++i < 3)
	{
		if (tfd[i] == 1)
			tfd[i] = fd;
	}
	return (fd);
}
