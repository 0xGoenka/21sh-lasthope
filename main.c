/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:30:22 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/14 18:29:37 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(void)
{
	//if (!error())
	//eturn (0);
	t_env	*env;
	char	*str;

	env = env_init();
	while (1)
	{
		str = readLine("21sh #> ", env->hist);
		//hist_add(env->hist, str);
		tree_exec(fill_tree(str), str, env);
		//ft_strdel(&str);
	}
	return (0);
}
