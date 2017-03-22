/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyandpast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:36:13 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/22 20:54:37 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	copy(t_line *line)
{
	int i;

	i = line->pos;
	copy_read(line);
	move_curs(i, *line);
	if (line->buffer_copy != NULL)
	{
		free(line->buffer_copy);
		line->buffer_copy = NULL;
	}
	line->buffer_copy = (char *)malloc(sizeof(char) * line->pos - i + 1);
	line->buffer_copy[line->pos - i] = 0;
	ft_strncpy(line->buffer_copy, line->str + i, line->pos - i);
	line->pos = i;
	print_end(*line);
	return (0);
}

void	copy_read(t_line *line)
{
	char	s[7];
	int		start;

	start = line->pos;
	while (s[0] != 27 || s[1] != 91 || s[2] != 0)
	{
//debug(line, (line->pos+line->plen) % col(), posy(*line), leny(*line));
		ft_bzero(s, 7);
		read(0, s, 6);
		if (s[0] == 27 && s[1] == 91 && s[2] == 67 && line->len > line->pos)
		{
			tputs(tgetstr("mr", 0), 0, outc);
			ft_putchar_fd(line->str[line->pos], line->h->fd);
			tputs(tgetstr("me", 0), 0, outc);
			line->pos++;
		}
		if (s[0] == 27 && s[1] == 91 && s[2] == 68 && line->pos != start)
		{
			move_curs(line->pos, *line);
			ft_putchar_fd(line->str[line->pos], line->h->fd);
			line->pos--;
			move_curs(line->pos, *line);
			check_bol(line, 0);
		}
		//if (s[0] == 27 && s[1] == 99 && s[2] == 0)
		//	break ;
	}
}

void	paste(t_line *line)
{
	s_add_s(line);
}
