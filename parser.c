/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:43:03 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/31 22:22:04 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		**parser(char *str, t_env *env)
{
	char **split;

	(void)env;
	split = ft_strsplit(str,' ');
	//ft_printtab(split);
	buildin(split, env);
	ft_tabdel(split);
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
	return (0);
}
