/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:30:22 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/01 15:42:05 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(void)
{
	//if (!error())
	//	return (0);
	t_env	*env;
	char	*str;

	env = env_init();
	while (1)
	{
		str = readLine("21sh #> ", env->hist);
		//if (str && ft_strcmp("exit", str) == 0)
		//	exit(1);
		//if (str && ft_strcmp("env", str) == 0)
		//	display_env(env);
		parser(str, env);
		ft_strdel(&str);
		//hist_add(hist, str);
	}
	return (0);
}
