/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:38:40 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/07 12:50:48 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


char	*readLine(char *prompt, t_hist *hist)
{
	char buf[7];
	t_line *line;
	struct termios *old_term;

	ft_signal();

	if (!(old_term = def_term()))
		disp_err(2);
	line = struct_init(prompt, hist);
	ft_putstr(line->prompt);
	while (42)
	{
		debug(line, (line->pos + line->plen) % col(),0,0);
		ft_bzero(buf, 7);
		read(0, buf, 6);
		if (key_pressed(buf, line) == -1)
			break;
	}
	move_curs(line->len, *line);
	restore_term(old_term);
	hist_add(hist, line->str);
	return (clean_line(line));
}
