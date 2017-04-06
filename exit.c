/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 22:49:02 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/03 20:44:57 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	super_exit(t_env *env)
{
	ft_tabdel(env->t);
	ft_tabndel(env->hist->tab, HLEN);
	free(env->hist);
	free(env);
	exit(EXIT_SUCCESS);
}

bool	b_echo(char **line)
{
	t_line *l;

	l = stock(NULL, 1);
	if (ft_tablen(line) == 1)
		return (ft_err("echo : error no arg.", NULL, NULL, 1));
	while (line && *line)
	{
		line++;
		ft_putstr_fd(*line, 1);
		if (line + 1)
		ft_putchar_fd(' ', 1);
	}
	ft_putchar_fd('\n', 1);
	return (1);
}

