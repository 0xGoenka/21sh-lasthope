/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:46:15 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/06 16:40:50 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_line	struct_init(char *prompt)
{
	t_line line;

	line.str = 0;
	line.prompt = ft_strdup(prompt);
	line.pos = 0;
	line.len = 0;

	return (line);
}
