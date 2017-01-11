/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:42:24 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/11 16:39:21 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	restore_curs(int x1, int x2)
{
	//x1 line.pos
	//x2 line.len
	
	tputs(tgoto(tgetstr("UP", 0), 0, y2 - y1), 0, outc);
	tputs(tgoto(tgetstr("ch", 0), 0, x1), 0, outc);
}
