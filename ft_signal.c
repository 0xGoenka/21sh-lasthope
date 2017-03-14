/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:28:43 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/14 18:27:24 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_line	*stock(t_line *l, int mode)
{
	static t_line	*stock = NULL;

	if (mode == 0)
		stock = l;
	return (stock);
}

void	ft_signal(void)
{
	int	sig;

	sig = 0;
	while (sig < 32)
	{
		if (sig == SIGWINCH)
			signal(sig, ft_sigint);
		else if (sig == SIGINT)
			signal(sig, ft_sigint);
		sig++;
	}
}

void	ft_sigint(int i)
{
	t_line *l;

	l = stock(NULL, 1);
	ft_strdel(&l->str);
	ft_strdel(&l->buffer_copy);
	ft_strdel(&l->quote);
	l->len = 0;
	l->pos = 0;
	l->plen = 8;
	l->h->pos = l->h->index - 1;
	ft_putchar('\n');
	ft_putstr(l->prompt);
	i++;
	return ;
}
