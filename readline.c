/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:38:40 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/06 16:41:04 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


char	readLine(char *prompt)
{
	char buf[7];
	t_line line;


	line = struct_init(prompt);

	ft_putstr(line.prompt);
	
	while (42)
	{
		ft_bzero(buf, 7);
		read(0, buf, 6);
	//	key_pressed(buf, line);
	}

	return (0);//(key_pressed(buf, line));


}
