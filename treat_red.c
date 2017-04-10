/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:05:30 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/10 22:02:37 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		treat_redir(char **t, char **tl, t_env *env)
{
	int fd[3];// ex ls > ls

	fd[0] = 0;
	fd[1] = 1;
	fd[2] = 2;
	
	//printf("1 == fd[0] == %d fd[1] == %d fd[2] == %d\n", fd[0], fd[1], fd[2]);
	parse_fd(&fd[0], tl);
	//printf("2  == fd[0] == %d fd[1] == %d fd[2] == %d\n", fd[0], fd[1], fd[2]);
	exec_redir(&fd[0], tl, env);
	return (0);
}

int		exec_redir(int *fd, char **t, t_env *env)
{

	int	exec;

	exec = find_exec(t);
	exec_redir2(&fd[0], t[exec], env);
	return (0);
}

int		exec_redir2(int *fd, char *cmd, t_env *env)
{
	int i;
	int save_stdout;
	int	save_stderr;
	int	save_stdin;

	save_stdout = dup(1);
	save_stderr = dup(2);
	save_stdin = dup(0);
	i = -1;

	while (++i < 3)
	{
		if (fd[i] == -3)
			close(i);
		else if(fd[i] != i)
			dup2(fd[i], i);
	}
	printf("fd[0] == %d fd[1] == %d fd[2] == %d\n", fd[0], fd[1], fd[2]);
	parser(cmd, env, 1);
	dup2(save_stdout, 1);
	dup2(save_stderr, 2);
	dup2(save_stdin, 0);
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
		if (((red = which_redir2(t[i])) > 0 && which_redir2(t[i]) < 9) || red == 3)
		{
			if (red == 1 || red == 2)
				fd[1] = open_file(t[i + 1], red);
			if (red == 5 || red == 6)
				fd[(t[i][0] - '0')] = open_file(t[i + 1], red);
			if (red == 7)
				fd[1] = fd[t[i][2] - '0'];
			if (red == 8)
				fd[t[i][0] - '0'] = fd[t[i][3] - '0'];
			if (red == 3)
				fd[0] = open_file(t[i + 1], red);
		}
			//printf("debug red = %d\n", red);
		i++;
	}
	return (0);
}
