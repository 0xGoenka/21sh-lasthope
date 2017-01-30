/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:30:22 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/25 19:15:38 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(void)
{
	//if (!error())
	//	return (0);
	t_hist	*hist;
	char	*str;

	hist = hist_init();
	while (1)
	{
		str = readLine("21sh #> ", hist);
		if (str && ft_strcmp("exit", str) == 0)
			exit(1);
		ft_strdel(&str);
		//hist_add(hist, str);
	}
	return (0);
}
