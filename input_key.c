/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:02:32 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/11 16:39:14 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	key_pressed(char *s, t_line *line)
{
	debug(line, (line->pos+line->plen) % col(), posy(*line), leny(*line));
	if (s[0] >= 32 && s[0] <= 126 && s[1] == 0) // it s a char
		return (letter(line, s[0]));
	if (s[0] == 27 && s[1] == 91 && s[2] == 68) // left
		return (key_le(line));
	if (s[0] == 27 && s[1] == 91 && s[2] == 67) // right
		return (key_ri(line));
	if (s[0] == 127 && s[1] == 0) //del
	       return (key_del(line));
//	if (s[0] == 21 && s[1] == 91 && s[2] == 66) // down
//		return (key_down());
//	if (s[0] == 21 && s[1] == 91 && s[2] == 65) // up
//		return (key_up());
	if (s[0] == 10 && s[1] == 0) // enter
		return (-1);
	return (0);	
}

int	letter(t_line *line, char c)
{
	
	line->str = s_add(line->str, c, line->pos);
	line->len++;
	line->pos++;
	ft_putchar(c);
	check_eol(line, 0);
	
	return (0);
}

int	key_del(t_line *line)
{
	if (!line->pos)
		return (0);
	line->str = s_del(line->str, (line->pos - 1));
	line->len--;
	line->pos--;
	//check_bol(line,0);
	print_end(*line);
	return (0);
}

bool	key_ri(t_line *line)
{
	if (line->pos == line->len)
		return (1);
	//else if (check_eol(line, 1))
	//	return (1);
	else
	{
		tputs(tgetstr("nd", 0), 0, outc);
		line->pos++;
		check_eol(line, 0);
	}
	return (1);

}

bool	key_le(t_line *line)
{
	if (!line->pos)
		return (1);
	else
	{
		tputs(tgetstr("le", 0), 0, outc);
		line->pos--;
		check_bol(line, 0);
	}
	return (1);
}
