/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defterm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 16:53:28 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/03 19:41:59 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct termios	*def_term(void)
{
	char			*term_name;
	struct termios	term;
	struct termios	*old_term;

	old_term = malloc(sizeof(struct termios));
	if (!(term_name = getenv("TERM")))
		return (NULL);
	if (tgetent(NULL, term_name) == ERR)
		return (NULL);
	if (tcgetattr(0, &term) == -1)
		return (NULL);
	tcgetattr(0, old_term);
	term.c_lflag &= ~(ECHO | ICANON);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (NULL);
	return (old_term);
}

bool		restore_term(struct termios *term_restore)
{
	tcsetattr(0, TCSANOW, term_restore);
	free(term_restore);
	ft_putchar('\n');
	return (1);
}
bool		clean_exit(t_line *line)
{
	line->pos = line->pos;
	return (0);	
}

/*struct termios get_env(struct termios term)
{
	static struct termios *t = NULL;
	if (t == NULL)
		return (t);
	else
		t = term;
	return (t);
	
}*/
