/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:46:15 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/10 17:24:43 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_line	*struct_init(char *prompt)
{
	t_line *line;

	line = (t_line *)malloc(sizeof(t_line));

	line->str = (char *)malloc(sizeof(char) * 1);
	line->str[0] = 0;
	line->prompt = ft_strdup(prompt);
	line->plen = ft_strlen(prompt);
	line->pos = 0;
	line->len = 0;

	return (line);
}
