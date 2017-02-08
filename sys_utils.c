/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:38:43 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/08 22:53:50 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**split_path(char **env)
{
	char		**path;
	char		*tmp;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp("PATH=", env[i], 5) != 0)
		i++;
	if (env[i] && ft_strncmp("PATH=", env[i], 5) == 0)
	{
		tmp = ft_strsub(env[i], 5, ft_strlen(env[i]) - 5);
		path = ft_strsplit(tmp, ':');
		free(tmp);
		return (path);
	}
	else
		return (0);
}

int		is_exec(char **param)
{
	if (!ft_strlen(param[0]))
		return (0);
	if (param[0][0] == '.' || param[0][0] == '/')
	{
		if (open(param[0], O_RDONLY) == -1)
		{
			ft_putstr("shell : no such file or directory : ");
			ft_putendl(param[0]);
			return (0);
		}
		if (opendir(param[0]))
		{
			ft_putstr("shell : permission denied : ");
			ft_putendl(param[0]);
			return (0);
		}
	}
	return (1);
}

char	*get_home_dir(char **env)
{
	char		*homepath;
	int			i;

	homepath = NULL;
	i = 0;
	while (env[i] && ft_strncmp("HOME=", env[i], 5) != 0)
		i++;
	if (env[i] && ft_strncmp("HOME=", env[i], 5) == 0)
		homepath = ft_strsub(env[i], 5, ft_strlen(env[i]) - 5);
	return (homepath);
}
void	change_env_val(char **env, char *key, char *newval)
{
	int i;
	char **split;

	i = 0;
	if (!env || !key)
		return ;
	while (env[i])
	{
		split = ft_strsplit(env[i], '=');
		if (strcmp(split[0], key) == 0)
		{
			ft_strdel(&env[i]);
			key = ft_saddc(key, '=', ft_strlen(key));
			env[i] = ft_strjoin(key, newval);
			ft_tabdel(split);
			return ;

		}
		ft_tabdel(split);
		i++;
	}	

}


char	*get_env_val(char **env, char *key)
{
	char **split;
	char *r;
	int i;

	i = 0;
	if (!env || !key)
		return (NULL);

	while (env[i])
	{
		split = ft_strsplit(env[i], '=');
		if (strcmp(split[0], key) == 0)
		{
			r = ft_strdup(split[1]);
			ft_tabdel(split);
			return (r);
		}
		ft_tabdel(split);
		i++;
	}
	return (NULL);
}
