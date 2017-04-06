/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 10:30:49 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/06 19:41:33 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main_redir(char *str, t_env *env)
{
	char **t;
	char ***r;

	if (check_redir2(str))
	{
		t = redir_to_tab(str);
		if ((t = check_redir(t)) == NULL)
			return (0);
		//ft_printtab(t);
		//ft_putendl("=== exec ====");
		//ft_putendl(t[find_exec(t)]);
		//ft_putendl("========");
		r = split_tab(t);
		//ft_putendl("===============tab 0");
		//ft_printtab(r[0]);
		//ft_putendl("================tab 1");
		//ft_printtab(r[1]);
		treat_redir(r[1], t, env);
		ft_tabdel(r[0]);
		ft_tabdel(r[1]);
		free(r);
		ft_tabdel(t);
	}
	return (0);
}

int		find_exec(char **t)
{
	int i;
	int red;

	i = 0;
	while (t[i] && (which_redir2(t[i]) > 6 || which_redir2(t[i]) < 1))
		i++;
	red = which_redir2(t[i]);
	while (i != -1 && which_redir2(t[i]) != -1)
		i--;
return (i);
}

char	***split_tab(char **t1)
{
	char	***t;
	char	**t2;
	char	**t3;
	int		i;

	i = 0;
	t2 = NULL;
	t3 = NULL;
	while (t1[i])
	{
		if (which_redir2(t1[i]) == -1)
			t2 = ft_tabaddstr(t2, t1[i]);
		else
			t3 = ft_tabaddstr(t3, t1[i]);
		i++;
	}
	t = (char ***)malloc(sizeof(char **) * 2);
	t[0] = t2;
	t[1] = t3;
	return (t);
}
