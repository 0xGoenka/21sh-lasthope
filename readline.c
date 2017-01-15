/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:38:40 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/11 03:08:51 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


char	readLine(char *prompt)
{
	char buf[7];
	t_line *line;
	struct termios *old_term;

	old_term = def_term();
	line = struct_init(prompt);
	ft_putstr(line->prompt);
	while (42)
	{
		//debug(line, (line->pos + line->plen) % col(),0,0);
		ft_bzero(buf, 7);
		read(0, buf, 6);
		if (key_pressed(buf, line) == -1)
		{
			restore_term(old_term);
			break;
		}
		debug(line, posx(*line), posy(*line), leny(*line));
	}

	return (0);//(key_pressed(buf, line));


}
