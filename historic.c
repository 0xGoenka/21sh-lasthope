/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:28:13 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/17 20:16:01 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

t_hist *hist_init(void)
{
	t_hist *h;
	int i;

	i = 0;
	h = (t_hist *)malloc(sizeof(t_hist));
	h->tab = (char **)malloc(sizeof(char*) * HLEN);
	h->pos = 0;
	h->index = 0;
	h->quote = NULL;
	h->status = 0;
	
	while (i < HLEN)
	{
		h->tab[i] = NULL;
		i++;
	}
	return (h);
}

void	hist_add(t_hist *h, char *s)
{
	if (s && *s && !h->status)
	{
		ft_strdel(&h->tab[h->index]);
		h->tab[h->index] = ft_strdup(s);
		h->index++;
		if (h->index == HLEN)
			h->index = 0;
	}
}

void	hist_read_up(t_line *l)
{
	//printf("poshist = %d histindex = %d\n", l->h->pos, l->h->index);
	if (l->h->pos == -1)
		l->h->pos = 0;
	if (l->h->art)
		if (l->h->pos == 0)
			l->h->pos = HLEN - 1;
		else
			l->h->pos--;
	else
		l->h->art = 1;
	//printf("poshist = %d histindex = %d\n", l->h->pos, l->h->index);
	if (l->h->pos != l->h->index && l->h->tab[l->h->pos])
	{
		free(l->str);
		l->str = ft_strdup(l->h->tab[l->h->pos]);
		move_curs(0, *l);
		l->pos = l->len = ft_strlen(l->str);
		tputs(tgetstr("cd", 0), 0, outc);
		printN(l->str);
	}
	else
		if (l->h->pos == HLEN - 1)
			l->h->pos = 0;
		else
			l->h->pos++;
}

void	hist_read_do(t_line *l)
{
	if ((l->h->pos + 1) % HLEN != l->h->index)
	{
		if (l->h->pos == HLEN - 1)
			l->h->pos = 0;
		else
			l->h->pos++;
		free(l->str);
		l->str = ft_strdup(l->h->tab[l->h->pos]);
		move_curs(0, *l);
		l->pos = ft_strlen(l->str);
		tputs(tgetstr("cd", 0), 0, outc);
		printN(l->str);
	}
	else if (l->h->art)
	{
		l->h->art = 0;
		ft_strdel(&l->str);
		move_curs(0, *l);
		l->len = l->pos = 0;
		tputs(tgetstr("cd", 0), 0, outc);
	}
}
