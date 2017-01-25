/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:28:43 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/25 12:03:52 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void 	ft_signal(void)
{
	int	sig;

	sig = 0;

	while (sig < 31)
	{
		if (i ==  SIGWINCH)
			signal(sig, ft_sigwinch);
		else if (i == SIGINT || i == SIGSTP)
			signal(sig, SIG_IGN);
	}
}
