/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:40:52 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/08 15:26:31 by eleclet          ###   ########.fr       */
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
	//int i;
	//char	**param;

	//param = NULL;
	//i = 0;
	tmpenv = ft_tabdup(env->t);
	opt = ft_getopt(line, "ui");
	if (opt.status == 1)
		return (1);
	if (env_alone(tmpenv, opt))
		return (1);
	if (env_i(opt))
		return (1);
	if (env_u(tmpenv, opt))
		return (1);
	/*if (!opt.opt && !opt.status)
		ft_printtab(env->t);
	if (ft_tablen(env->t) == 0)
		ft_putendl("Env: is empty.");

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

*/
	return (1);
}
bool		env_alone(char **env, t_opt opt)
{
	if (!opt.opt && !opt.arg)
		ft_printtab(env);
	else if (ft_tablen(env) == 0)
		ft_putendl("Env is empty.");
	else if (!opt.opt && opt.arg)
	{
		if (!basic_exec(opt.arg, env))
			exec_bin(opt.arg, env, split_path(env));
	}
	else 
		return (0);
	return (1);	
}

bool		env_i(t_opt opt)
{
	if (!ft_strchr(opt.opt, 'i'))
		return (0);
	if (!ft_strchr(opt.opt, 'u'))
	{
		if (opt.arg)
			if (!basic_exec(opt.arg, NULL))
				exec_bin(opt.arg, NULL, NULL);
		return (1);
	}
	else
	{
		if (!opt.arg)
			ft_putendl("missing arg for -u");
		if (ft_tablen(opt.arg) > 1)
		{
			if (!basic_exec(opt.arg + 1, NULL))
				exec_bin(opt.arg + 1, NULL, NULL);
		}
		return (1);	
	}
	return (0);

}

bool		env_u(char **env, t_opt opt)
{
	int i;

	if (!opt.arg)
	{
		ft_putendl("missing arg for -u");
		return (0);
	}
	i = ft_tabchr(env, opt.arg[0], '=');
	if (i != -1)
		env = ft_tabrmstr(env, env[i]);
	if (ft_tablen(opt.arg) == 1)
		ft_printtab(env);
	else
	{
		if (!basic_exec(opt.arg + 1, env))
			exec_bin(opt.arg + 1, env, split_path(env));
	}
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
