/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:40:52 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/07 21:22:52 by eleclet          ###   ########.fr       */
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
	t_opt opt;
	char	**tmpenv;
	int i;
	char	**param;

	param = NULL;
	i = 0;
	tmpenv = ft_tabdup(env->t);
	opt = ft_getopt(line, "ui");
	if (!opt.opt && !opt.status)
		ft_printtab(env->t);
	if (ft_tablen(env->t) == 0)
		ft_putendl("  || warning : Env is empty ||");
	if (!opt.arg && ft_strchr(opt.opt, 'u'))
		ft_putendl("env : option require an argument -- 'u'");
	if (ft_strchr(opt.opt, 'u') && opt.arg)
		tmpenv = ft_tabrmstr(tmpenv, tmpenv[ft_tabchr(tmpenv,
					opt.arg[0], '=')]);
	if (ft_strchr(opt.opt, 'i'))
		ft_tabdel(tmpenv);
	if (ft_tablen(opt.arg) == 1)
		ft_printtab(tmpenv);
	while (opt.arg && opt.arg[++i])
		param = ft_tabaddstr(param, opt.arg[i]);
	if (param && !basic_exec(param, tmpenv))
		exec_bin(param, tmpenv, split_path(tmpenv));


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
