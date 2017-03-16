/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 20:35:14 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/16 14:14:19 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_err(char *msg, char *var1, char *var2, int ret)
{
	ft_putstr("\x1B[31m");
	ft_putstr(msg);
	ft_putstr("\x1B[0m");
	printN(var1);
	ft_putendl(var2);
	return (ret);
}
