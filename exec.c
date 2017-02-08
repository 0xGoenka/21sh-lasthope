/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:03:36 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/07 21:30:21 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	basic_exec(char **param, char **env)
{
	pid_t pid;
	//int status;

	//if (is_exec(param) == 0)
	//	return (0);
	if (param[0][0] == '.' || param[0][0] == '/')
	{
		if (access(param[0], X_OK) == 0)
		{
			pid = fork();
			if (pid > 0)
				waitpid(pid, NULL, 0);
			else
				execve(param[0], param, env);
			return (1);
		}	
	}
	return (0);

	
}

int	exec_bin(char **env, char **param, char **path)
{
	pid_t pid;
	int status;
	char *tmp;
	char *tmp2;
	int i;
	
	i = 0;
	while (path && path[i])
	{
		tmp = ft_strjoin(path[i], (tmp2 = ft_strjoin("/", param[0])));
		ft_strdel(&tmp2);
		if (access(tmp, X_OK) == 0)
		{
			pid = fork();
			if (pid > 0)
				waitpid(pid, &status, 0);
			else
				execve(tmp, param, env);
			return (1);
		}
		i++;
	}
	ft_putendl("shell : command not found");
	return (1);	
}
