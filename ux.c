/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ux.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 21:54:33 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/10 15:57:11 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	check_eol(t_line *line, int p)
{
	debug(line, (line->pos + line->plen) % col(),0,0);
	if ((line->pos + line->plen) % col() == 0)// && line.len > col() / 2)
	{
		tputs(tgetstr("do", 0), 0, outc);
		if (p)
		{
			line->pos++;
		}
		return (1);
	}
	else
		return (0);
}

bool	check_bol(t_line *line, int p)
{
	debug(line, (line->pos + line->plen) % col(),0,0);
	if ((line->pos + line->plen) % col() == 0)
	{
		tputs(tgetstr("up", 0), 0, outc);
		tputs(tgoto(tgetstr("RI", 0), 0, col()), 0, outc);
		if (p)
			line->pos--;
		return (1);
	}
	else
		return (0);
}
