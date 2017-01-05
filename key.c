/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:40:21 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/03 19:41:25 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int	 movecursor(char *s, t_line *line)
{
	if (s[0] == 27 && s[1] == 91 && s[2] == 68) // left
    {
        goleft(line);
        return (1);
    }
	if (s[0] == 27 && s[1] == 91 && s[2] == 67) // right
	{
		goright(line);
		return (1);
	}
	if (s[0] == 127 && s[1] == 0) // del
	{
		delelem(line);
		tputs(tgetstr("cd", 0), 0, outc);
		printend(line, 1);
		return (1);
	}
	if (s[0] == 21 && s[1] == 91 && s[2] == 66) // down
 	{
		return (0);
	}
	if (s[0] == 21 && s[1] == 91 && s[2] == 65) // up
 	{
		return (0);
	}
	return (0);
}

char key(char *s)
{
	if (s[1] == 0 && s[0] >= 32 && s[0] <= 126)
		return (s[0]);
	return (0);
}

void goright(t_line *line)
{
    if (line->poslen == line->len)
        return ;
    if (godown(line, 1))
    {
		line->poslen++;
        line->lenx = col();

    }
	else
	{
    	tputs(tgetstr("nd", 0), 0, outc);
    	line->posx++;
		line->poslen++;
	}
}

void goleft(t_line *line)
{
    if (line->posx == 0 && !line->posy)
        return ;
    if (line->posx == 0 && line->posy == 1)
    {
        tputs(tgetstr("up", 0), 0, outc);
		to_end_line();
        line->posy--;
        line->poslen--;
        line->posx = col() - 8;
        line->lenx = col() - 8;
        return ;
    }
    if (line->posx == 0 && line->posy > 1)
    {
        tputs(tgetstr("up", 0), 0, outc);
	to_end_line();
        line->posy--;
	line->poslen--;
        line->posx = col() - 1;
        line->lenx = col() - 1;
        return ;
    }

    tputs(tgetstr("le", 0), 0, outc);
    line->posx--;
	line->poslen--;
}
