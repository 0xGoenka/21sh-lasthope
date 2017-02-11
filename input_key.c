/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:02:32 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/11 00:31:10 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	key_pressed(char *s, t_line *line)
{
	//debug(line, (line->pos+line->plen) % col(), posy(*line), leny(*line));
	/*ft_putnbr(s[0]);
	ft_putnbr(s[1]);
	ft_putnbr(s[2]);
	ft_putnbr(s[3]);
	ft_putnbr(s[4]);
	ft_putnbr(s[5]);*/
	if (IS_CHAR) // it s a char
		return (letter(line, s[0]));
	if (KEY_LE) // left
		return (key_le(line));
	if (KEY_RI) // right
		return (key_ri(line));
	if (BACKSPACE) //backspace
	       return (key_del(line));
	if (DEL) // key suppr
		return (key_suppr(line));
	if (CTRL_D)
		return (-1);
	if (CTRL_DO) // down
		return (key_do(line));
		if (CTRL_UP) // up
		return (key_upp(line));
	if (HOME) // home
		return (key_ho(line));
	if (END) // end
		return (key_en(line));
	if (CTRL_RIGHT) // ctrl right
		return (key_next_word(line));
	if (CTRL_LEFT) // ctrl left
		return (key_prev_word(line));
	if (ALT_C) // alt + c
		return (copy(line));
	if (ALT_V)
		paste(line);
	if (ENTER) // enter
		return (-1);
	if (KEY_UPP)
		hist_read_up(line);
	if (KEY_DO)
		hist_read_do(line);
	return (0);	
}

int	letter(t_line *line, char c)
{
	
	line->str = s_add(line->str, c, line->pos);
	line->len++;
	line->pos++;
	ft_putchar(c);
	check_eol(line, 0);
	print_end(*line);
	
	return (0);
}
bool	key_suppr(t_line *line)
{
	if (line->pos == line->len)
		return (0);
	line->str = s_del(line->str, line->pos);
	line->len--;
	print_end(*line);
	
	return (0);	
}
int	key_del(t_line *line)
{
	if (!line->pos)
		return (0);
	line->str = s_del(line->str, (line->pos - 1));
	line->len--;
	line->pos--;
	if (!check_bol(line,0))
		tputs(tgetstr("le", 0), 0 , outc);
	print_end(*line);
	
	return (0);
}

bool	key_ri(t_line *line)
{
	if (line->pos == line->len)
		return (1);
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

bool	key_upp(t_line *line)
{
	if (posy(*line) == 0)
		return (0);
	if (posy(*line) == 1 && posx(*line) < line->plen )
		return (0);
	move_curs(line->pos - col() , *line);
	line->pos = line->pos - col();
	return (1);
}

bool	key_do(t_line *line)
{
	if (line->pos + col() > line->len)
		return (0);
	move_curs(line->pos + col(), *line);
	line->pos = line->pos + col();
	return (1);
		
}
bool	key_ho(t_line *line)
{
	if (line->pos == 0)
		return (0);
	move_curs(0, *line);
	line->pos = 0;
	return (1);
}

bool	key_en(t_line *line)
{
	if (line->pos == line->len)
		return (0);
	move_curs(line->len, *line);
	line->pos = line->len;
	return (1);
	
}

bool	key_next_word(t_line *line)
{
	int i;

	i = line->pos;
	while (line->str[i] && line->str[i] != 32)
		i++;
	while (line->str[i] && line->str[i] == 32)
		i++;
	if (i != line->len)
	{
		move_curs(i, *line);
		line->pos = i;
	}
	return (1);
}

bool	key_prev_word(t_line *line)
{
	int i;
	int k;

	k = 0;
	i = line->pos;
	while (i && line->str[i] != 32)
		i--;
	while (i && line->str[i] == 32)
		i--;
	while (i && line->str[i] != 32)
		i--;
	if (i)
		k = 1;
	move_curs(i + k, *line);
	line->pos = i + k;
	return (1);
}
