/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:38:43 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/02 15:19:49 by eleclet          ###   ########.fr       */
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
