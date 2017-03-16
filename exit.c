/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 22:49:02 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/16 16:57:52 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	super_exit(t_env *env)
{
	ft_tabdel(env->t);
	ft_tabdel(env->hist->tab);
	free(env->hist);
	free(env);
	exit(EXIT_SUCCESS);
}

bool	b_echo(char **line)
{
	if (ft_tablen(line) == 1)
		return (ft_err("echo : error no arg.", NULL, NULL, 1));
	while (line && *line)
	{
		line++;
		ft_putstr(*line);
		ft_putchar(' ');
	}
	ft_putchar('\n');
	return (1);
}

