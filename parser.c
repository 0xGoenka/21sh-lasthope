/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:43:03 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/02 15:32:53 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		**parser(char *str, t_env *env)
{
	char **param;

	if (!(param = ft_strsplit(str,' ')))
		return (NULL);
	buildin(param, env);
	basic_exec(param, env->t);
	exec_bin(env->t, param, split_path(env->t));
	ft_tabdel(param);
	return (NULL);
}

/*char	*ft_getopt(char **line, char *allowed) // alowed est un liste des option existente;
{
	int i;

	i = 1;
	while (line[1])
	{
		
	}
}*/

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
