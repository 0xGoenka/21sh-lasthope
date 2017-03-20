/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigwinch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:54:32 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/17 20:16:10 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_sigwinch(int i)
{
	t_line *l;

	l = stock(NULL, 1);
	//if (col() * row() < l->len + l->plen)
	move_curs(0, *l);
	tputs(tgetstr("cd", 0), 0, outc);
	printN(l->str);
	l->pos = l->len;
	i++;
	return ;
}
