/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:28:43 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/25 19:15:41 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void 	ft_signal(void)
{
	int	sig;

	sig = 0;

	while (sig < 32)
	{
		if (sig ==  SIGWINCH)
			signal(sig, ft_sigint);
		else if (sig == SIGINT)
			signal(sig, ft_sigint);
		sig++;
	}
}

void	ft_sigint(int i)
{
	exit(i);
	return ;
}
