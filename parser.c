/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:43:03 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/08 22:53:46 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		**parser(char *str, t_env *env)
{
	char **param;

	if (!(param = ft_strsplit(str,' ')))
		return (NULL);
	if (!buildin(param, env))
		if (!basic_exec(param, env->t))
			exec_bin(env->t, param, split_path(env->t));
	ft_tabdel(param);
	return (NULL);
}


bool		buildin(char **line, t_env *env)
{
	if (ft_strcmp(line[0], "setenv") == 0)
		return (set_env(line, env));
	if (ft_strcmp(line[0], "exit") == 0)
		exit(1);
	if (ft_strcmp(line[0], "env") == 0)
		return (display_env(line, env));
	if (ft_strcmp(line[0], "unsetenv") == 0)
		return (unset_env(line, env));
	if (ft_strcmp(line[0], "cd") == 0)
		return (cd(env->t, line));
	return (0);
}
