/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ux.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 21:54:33 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/11 16:39:26 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	check_eol(t_line *line, int p)
{
	if ((line->pos + line->plen) % col() == 0)
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
	//debug(line, (line->pos + line->plen) % col(),0,0);
	if ((line->pos + line->plen) % col() == col() - 1)
	{
		tputs(tgetstr("up", 0), 0, outc);
		tputs(tgoto(tgetstr("ch", 0), 0, col() -1), 0, outc);
		if (p)
			line->pos--;
		return (1);
	}
	else
		return (0);
}

void	print_end(t_line line)
{
	int i;

	i = line.pos;
	if (!check_bol(&line,0))
		tputs(tgetstr("le",0),0, outc);
	tputs(tgetstr("cd", 0), 0, outc);
	//if (line.pos == line.len)
	//{
	//	line.pos++;
	//	line.len++;	
	//	check_bol(&line, 0);
	//	tputs(tgetstr("cd",0),0,outc);
	//	return ;
	//}
	while (i < line.len)
	{
		ft_putchar(line.str[i]);
		i++;
	}
	restore_curs(line);
	debug(&line, line.pos+line.plen, (line.len+line.plen - 1) / col() , (line.pos + line.plen - 1)/ col());
}

int	posx(t_line line)
{
	return ((line.pos + line.plen) % col());
}

int	posy(t_line line)
{
	int i;

	i = (line.pos + line.plen - 1) / col();

	return (i);
}

int	leny(t_line line)
{
	int i;

	i = (line.len + line.plen - 1) / col();

	return (i);
}
