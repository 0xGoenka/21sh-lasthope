/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:28:13 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/24 12:15:22 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

t_hist *hist_init(void)
{
	t_hist *h;

	h = (t_hist *)malloc(sizeof(t_hist));
	h->tab = (char **)malloc(sizeof(char*) * HLEN);
	h->pos = 0;
	h->index = 0;
	
	//while (i < HLEN)
	//{
	//	tab[i] = (char *)malloc(sizeof(char) * 1);
	//	tab[i][0] = 0;
	//	i++;
	//}
	return (h);
}

void	hist_add(t_hist *h, char *s)
{
	if (*s)
	{
		h->tab[h->index] = ft_strdup(s);
		h->index++;
		if (h->index == HLEN)
			h->index = 0;
	}
}

void	hist_read_up(t_line *l)
{
	if (l->h->pos != l->h->index && l->h->tab[l->h->pos])
	{
		if (l->h->art)
		{
			if (l->h->pos == 0)
				l->h->pos = HLEN - 1;
			else
				l->h->pos--;
		}
		else
			l->h->art = 1;
		free(l->str);
		l->str = ft_strdup(l->h->tab[l->h->pos]);
		move_curs(0, *l);
		l->pos = l->len = ft_strlen(l->str);
		tputs(tgetstr("cd", 0), 0, outc);
		ft_putstr(l->str);
	
	}
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
		ft_putstr(l->str);
	}
}
