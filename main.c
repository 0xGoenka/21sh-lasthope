/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:30:22 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/28 17:01:35 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(void)
{
	//if (!error())
	//eturn (0);
	t_env	*env;
	char	*str;
	t_tree *t;
	t_line *l;

	env = env_init();
	while (1)
	{
		str = readLine("21sh #> ", env->hist);
		//hist_add(env->hist, str);
		t = fill_tree(ft_strdup(str), env->t);
		chk_t(t);
		if (tree_error(42) == 0)
			tree_exec(t, env);
		isfirstfork(0);
		tree_error(0);
		tree_clean(t);
		l = stock(NULL, 1);
		clean_line(l);

	}
	return (0);
}
