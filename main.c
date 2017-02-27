/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:30:22 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/12 15:45:20 by eleclet          ###   ########.fr       */
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
		str = readLine("21sh #> ", env->hist);\
		hist_add(hist, str);
		parser(str, env);
		ft_strdel(&str);

	}
	return (0);
}
