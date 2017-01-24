/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:30:22 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/24 12:49:02 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(void)
{
	//if (!error())
	//	return (0);
	t_hist	*hist;
	//char	*str;

	hist = hist_init();
	while (1)
	{
		free(readLine("21sh #> ", hist));
		//hist_add(hist, str);
	}
	return (0);
}
