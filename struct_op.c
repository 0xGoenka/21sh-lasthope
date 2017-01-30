/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:46:15 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/25 19:15:40 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_line	*struct_init(char *prompt, t_hist *h)
{

	t_line *line;
	int	i;

	i = 0;
	line = (t_line *)malloc(sizeof(t_line));

	//line->str = (char *)malloc(sizeof(char) * 1);
	line->str = NULL;
	line->buffer_copy = NULL;
	line->prompt = ft_strdup(prompt);
	line->plen = ft_strlen(prompt);
	line->pos = 0;
	line->len = 0;
	line->h = h;
	i = (line->h->index - 1) % HLEN;
	if (i < 0)
		line->h->pos = 4;
	else
		line->h->pos = i;
	line->h->art = 0;
	return (line);
}
