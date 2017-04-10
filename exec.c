/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:03:36 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/10 21:54:37 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	basic_exec(char **param, char **env, int forkit)
{
	pid_t pid;

	if (!is_exec(param))
		return (0);
	//if (param[0][0] == '.' || param[0][0] == '/')
	//{
		if (access(param[0], X_OK) == 0)
		{
			if (isfirstfork(42) && forkit == 0)
			{
				execve(param[0], param, env);
				exit(1);
			}
			pid = fork();
			if (pid > 0)
				wait(&pid);//waitpid(pid, NULL, 0);
			else
			{
				execve(param[0], param, env);
				exit(1);
			}
			return (0);
		}
		return (1);	
	//}
	//return (0);

	
}

int	exec_bin(char **env, char **param, char **path, int forkit)
{
	pid_t pid;
	char *tmp;
	char *tmp2;
	int i;
	
	forkit++;
	i = -1;
	while (path && path[++i])
	{
		tmp = ft_strjoin(path[i], (tmp2 = ft_strjoin("/", param[0])));
		ft_strdel(&tmp2);
		if (access(tmp, X_OK) == 0)
		{
			if (isfirstfork(42) && forkit == 0)
			{
				execve(tmp, param, env);
				exit(1);
			}
			pid = fork();
			if (pid > 0)
				wait(&pid);//waitpid(pid, 0, 0);
			else
			{	
				execve(tmp, param, env);
				exit(1);
			}
			ft_strdel(&tmp);
			ft_tabdel(path);
			return (1);
		}
		ft_strdel(&tmp);
	}
	ft_tabdel(path);
	if (param == NULL)
		return (ft_err("shell : command not found : ", NULL, NULL, 1));
	else
		return (ft_err("shell : command not found : ", param[0], NULL, 1));
}
