/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:42:24 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/11 16:39:21 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	restore_curs(t_line line)
{
	
	//x1 line.pos
	//x2 line.len
	//int i;
	//int k;
	int pos;
	int ly;
	int py;

	pos = line.pos + line.plen;
	ly = leny(line);
	//if (len % col())
	//	leny++;
	py = posy(line);
	//if  (pos % col())
	//	posy++;
	//if (leny-posy && pos % col() != 0)
	if (ly - py > 0)
		tputs(tgoto(tgetstr("UP", 0), 0, ly-py), 0, outc);
	//if (pos % col() == col()-1 && len == pos )
	//	tputs(tgoto(tgetstr("UP", 0), 0, 1), 0, outc);
		
	tputs(tgoto(tgetstr("ch", 0), 0, pos % col()),0,outc);
	/*

	k = 0;
	if (pos == len)
		k = -1;
	else
		k = 1;
	i = pos % col();
	i = i + len - pos;
	if (i-k >= col())
		tputs(tgoto(tgetstr("UP", 0), 0, (i) / col()), 0, outc);
	tputs(tgoto(tgetstr("ch", 0), 0, pos % col()), 0, outc);*/
}
