/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:31:43 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/06 16:41:24 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "libft/libft.h"
# include <stdbool.h>
# include <termcap.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <stdio.h>

typedef struct	s_line
{
	char *str;
	char *prompt;
	int	plen;
	int 	pos;
	int	len;
}		t_line;

int		col(void);
int		row(void);

bool		def_term(void);
bool		init_error(void);
bool		error(void);

char		*s_add(char *s, char c, int pos);
char		*s_del(char *s, int pos);

char		readLine(char *prompt);

char		key_pressed(char *s, t_line *line);

char		*readLineMaster(void);
t_line		*struct_init(char *prompt);

int		outc(int c);
int		letter(t_line *line, char c);
int		key_del(t_line *line);
bool		key_le(t_line *line);
bool		key_ri(t_line *line);

bool    check_eol(t_line *line, int p);
bool    check_bol(t_line *line, int p);
void    print_end(t_line line);
int     posx(t_line line);
int     posy(t_line line);
int     leny(t_line line);

void    restore_curs(t_line line);
int	cursrow(int fd);
int	curscol(int fd);
int             debug(t_line *line, int a, int b, int c);




# endif
