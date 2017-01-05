/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:31:43 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/03 19:41:48 by eleclet          ###   ########.fr       */
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
int		col(void);
int		row(void);

char		*readline(void);

bool		def_term(void);
bool		init_error(void);
bool		error(void);

char		*s_add(char *s, char c, int pos);
char		*s_del(char *s, int pos);
# endif
