/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:13:10 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/08 22:53:47 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static bool	cd_alone(char **env, char **line)
{
	char *pwd;
	char *oldpwd;
	if (ft_tablen(line) < 2)
		return (0);
	if (ft_strcmp(line[1],"-") == 0 && ft_tablen(line) == 2)
	{
		pwd = get_env_val(env, "PWD");
		oldpwd = get_env_val(env, "OLDPWD");
	
		if (chdir(oldpwd) == 0)
		{
			change_env_val(env, ft_strdup("PWD"), oldpwd);
			change_env_val(env, ft_strdup("OLDPWD"), pwd);
		}
		return (1);
	}
	return (0);
		
}

static bool	cd_l(char **env, char **line, t_opt opt)
{
	if (opt.opt[0] != 'L')
		return (0);

	
}
static bool	cd_path(char **env, t_opt opt)
{
	char *pwd;

	if (ft_strlen(opt.opt) != 0 || !opt.arg)
		return (0);
	if (chdir(opt.arg[0]) == 0)
	{
			pwd = get_env_val(env, "PWD");
			change_env_val(env, ft_strdup("PWD"), opt.arg[0]);
			change_env_val(env, ft_strdup("OLDPWD"), pwd);
	}
	else
		return (ft_err("cd : no such directory.",1));
	return (1);
}


bool		cd(char **env, char **line)
{
	char *home;
	t_opt opt;

	if (cd_alone(env, line))
		return (1);
	opt = ft_getopt(line, "PL");
	if (opt.status)
		return (1);
	if (ft_tablen(opt.arg) > 1)
		return (ft_err("cd : too many args.", 1));
	if (cd_path(env, opt))
		return (1);
	if (ft_tablen(line) == 1)
	{
		if(!(home = get_env_val(env, "HOME")))
			return (ft_err("cd : home var not set.", 1));
		if (chdir(home))
			return (ft_err("cd : no such directory.", 1));
	}
	return (1);
}

