/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 15:44:58 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/20 15:47:02 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void	chk_t(t_tree *t)
{
	if (!t)
		return ;
	if (t->type)
	{
		if (!t->left || !t->right)
		{
			ft_putendl("Parsing error");
			tree_error(1);
			return ;
		}
		if (t->left->type && t->right->type)
		{
			ft_putendl("Parsing error 2");
			tree_error(1);
			return ;
		}
	}
	chk_t(t->right);
	chk_t(t->left);
}

int		tree_error(int i)
{
	static int status = 0;

	if (i == 42)
		return (status);
	return (( status = i));
}

int		isfirstfork(int i)
{
	static int n = 0;

	if (i == 42)
		return (n);
	return ((n = i));	
}

int		ft_fork(char *cmd1, char *cmd2, t_env *env)
{

	int		pipefd[2];
	pid_t	pid;

	pipe(pipefd);
	//if (isfirstfork(42) == 0)
	pid = fork();
	if (pid == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		parser(cmd1, env);
		exit(EXIT_SUCCESS);
	}
	if (pid)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
		parser(cmd2, env);
		wait(&pid);
	}
	return (1);
}
