/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:50:21 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/01 20:38:34 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	disp_err(int code)
{
	if (code == 0)
	{
		ft_putendl("an error occured : usage setenv something=something");
		return (1);
	}
	else if (code == 1)
		ft_putendl("Entry not found");
	else
	{
		printf("%d\n", code);
			return (0);
	}
	return (0);
}
