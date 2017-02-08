/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:52:52 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/08 16:00:31 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int arc, char **argv)
{
	t_opt opt;

	ft_printtab(argv);
	opt = ft_getopt(argv, "ui");
	ft_putendl("agr :");
	ft_printtab(opt.arg);
	ft_putstr("opt  ::  ");
	ft_putendl(opt.opt);

	return (0);
}
