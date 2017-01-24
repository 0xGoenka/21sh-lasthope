/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:42:24 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/24 12:48:38 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	restore_curs(t_line line)
{	
	int pos;
	int ly;
	int py;

	pos = line.pos + line.plen;
	ly = leny(line);
	py = posy(line);
	if (ly - py > 0)
		tputs(tgoto(tgetstr("UP", 0), 0, ly-py), 0, outc);
	tputs(tgoto(tgetstr("ch", 0), 0, pos % col()),0,outc);
}

void	move_curs(int x, t_line line)
{
	int py  = posy(line);
	int ly = (x + line.plen) / col();
	if (py - ly > 0)
		tputs(tgoto(tgetstr("UP", 0), 0, py - ly), 0, outc);
	tputs(tgoto(tgetstr("ch", 0), 0, (x + line.plen) % col()), 0, outc);
	if (ly - py > 0)
		tputs(tgoto(tgetstr("DO", 0), 0, ly - py), 0, outc);
}

char	*clean_line(t_line *line)
{
	char *s;

	s = ft_strdup(line->str);
	ft_strdel(&line->buffer_copy);
	ft_strdel(&line->str);
	ft_strdel(&line->prompt);
	free(line);

	return (s);
}

