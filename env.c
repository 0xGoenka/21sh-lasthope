/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:40:52 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/02 15:35:35 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_env		*env_init(void)
{
	extern char **environ;
	t_env *env;

	env = (t_env *)malloc(sizeof(t_env));
	env->hist = hist_init();
	env->t = ft_tabdup(environ);
	return (env);
}

bool		display_env(char **line, t_env *env)
{
	(void)line;
	ft_printtab(env->t);
	if (ft_tablen(env->t) == 0)
		ft_putendl("  || warning : Env is empty ||");
	return (1);
}

bool		set_env(char **line, t_env *env)
{
	int i;
	char **arg;

	arg = ft_strsplit(line[1], '=');
	if (ft_tablen(line) != 2 || ft_strcnt(line[1], '=') != 1 || 
			ft_tablen(arg) != 2)
	{
		ft_tabdel(arg);
		return (disp_err(0));
	}
	if ((i = ft_tabchr(env->t, ft_strjoin(arg[0], "="), '=')) >= 0)
	{
		free(env->t[i]);
		env->t[i] = ft_strjoin(arg[0], ft_strjoin("=", arg[1]));	
	}
	else
		env->t = ft_tabaddstr(env->t, line[1]);
	return (1);	
}

bool		unset_env(char **line, t_env *env)
{
	int i;

	if (!line || ft_tablen(line) != 2)
		return (disp_err(1));
	i = ft_tabchr(env->t, line[1], '=');
	if (i == -1)
		ft_putendl("Entry not found");
	else
	{
		env->t = ft_tabrmstr(env->t, env->t[i]);
	}
	return (1);
}
