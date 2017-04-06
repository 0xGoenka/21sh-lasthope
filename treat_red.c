/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:05:30 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/06 20:56:51 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		treat_redir(char **t, char **tl, t_env *env)
{
	int fd[3];// ex ls > ls

	fd[0] = 0;
	fd[1] = 1;
	fd[2] = 2;
	
	//printf("fd[0] == %d fd[1] == %d fd[2] == %d\n", fd[0], fd[1], fd[2]);
	parse_fd(&fd[0], t);
	//printf("fd[0] == %d fd[1] == %d fd[2] == %d\n", fd[0], fd[1], fd[2]);
	exec_redir(&fd[0], tl, env);
	return (0);
}

int		exec_redir(int *fd, char **t, t_env *env)
{

	int file;
	int red;
	int	exec;
	int fdf;

	file = exec = find_exec(t);
	while (which_redir2(t[file]) != 1 && which_redir2(t[file]) != 2)
		file++;
	red = which_redir2(t[file]);
	while (which_redir2(t[file]) != -1)
		file++;
	ft_putendl("ish");
	fdf = open_file(t[file], red, &fd[0]);
	if (env)
		file++; // del thissoon
	//printf("fd[0] == %d fd[1] == %d fd[2] == %d\n", fd[0], fd[1], fd[2]);
	exec_redir2(&fd[0], t[exec], env);
	close(fdf);
	return (0);
}

int		exec_redir2(int *fd, char *cmd, t_env *env)
{
	int i;
	int save_stdout;

	save_stdout = dup(1);
	i = 0;

	while (++i < 3)
	{
		if (fd[i] == -3)
			close(i);
		else if(fd[i] != i)
			dup2(fd[i], i);
	}
	parser(cmd, env, 1);
	dup2(save_stdout, 1);
	i = 0;
	while (++i < 3)
		if (fd[i] > 2)
			close(fd[i]);
	return (0);
}

int		parse_fd(int *fd, char **t)
{
	int i;
	int red;

	i = 0;
	while (t[i])
	{
		if ((red = which_redir2(t[i])) > 4 && which_redir2(t[i]) < 9)
		{
			printf("debug red = %d\n", red);
			if (red == 5 || red == 6)
				fd[(t[i][0] - '0')] = 1;
			if (red == 7)
				fd[1] = t[i][2] - '0';
			if (red == 8)
				fd[t[i][0] - '0'] = t[i][3] - '0';
		}
		i++;
	}
	return (0);
}
