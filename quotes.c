/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 00:30:02 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/17 11:59:06 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*char	*quotes(t_hist *hist,char *str)
{
	char *s1;
	char *s2;

	if (!need_quote(str) || hist->status || hist->ctrl_c)
		return str;
	hist->status = 1;
	while (need_quote(str))
	{
		s1 = readLine("quotes !>", hist);
		s1 = ft_saddc(s1, '\n', 0);
		s2 = ft_strjoin(str, s1);
		ft_strdel(&str);
		str = s2;
		ft_strdel(&s1);
	}
	hist->status = 0;
	return (str);
}*/

bool	main_quote(t_line *line)
{
	char *tmp;

	if (line->quote)
	line->str = ft_saddc(line->str, '\n', 0);
	tmp = ft_strjoin(line->quote, line->str);
	ft_strdel(&line->quote);
	line->quote = tmp;
	if (!need_quote(line->quote))
	{
		ft_strdel(&line->str);
		line->str = line->quote;
		line->plen = 8;
		return (0);
	}
	ft_strdel(&line->str);
	line->pos = 0;
	line->len = 0;
	line->plen = ft_strlen("quotes !> ");
	ft_putstr("\nquotes !> ");
	return (1);
}

bool	need_quote(char *str)
{
	while (str && *str)
	{
		if (*str == '\'')
		{
			str++;
			while (*str && *str != '\'')
				str++;
			if (*str == 0)
				return (1);
		}
		if (*str == '\"')
		{
			str++;
			while (*str && *str != '\"')
				str++;
			if (*str == 0)
				return (1);
		}
		str++;
	}
	return (0);
}

char	*replace_dollar(char *s, char **tab)
{
	char *r = NULL;
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (s &&s[i])
	{
		if (s[i] == '\'')
			while (s[++i] != '\'' && s[i]);
		if (s[i] == '$')
		{
			j = i+ 1;
			while (s[j] && ft_isletternum(s[j]) && s[j] != ' ')
				j++;
			r = ft_strndup(s + i + 1 , j - i - 1);
			if ((j = ft_tabchr(tab, r, '=')) == -1)
				while (s[i] && s[i] != ' ')
					s = ft_sdelc(s, i);
			else
				s = (ft_repdol(s, tab[j] + ft_strlen(r) + 1, i , ft_strlen(r) + 1));
		}
		if (s[i])
			i++;
	}
	ft_strdel(&r);
	return (s);
}
char	*parse_quote(char *s)
{
	int i;
	char c;
	char *r;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			c = s[i];
			s = ft_sdelc(s, i);
			while (s[i] && s[i] != c)
				i++;
			s = ft_sdelc(s, i--);
		}
		i++;
	}
	r = ft_strdup(s);
	ft_strdel(&s);
	return (r);
}
	
	/*
	while (s && *s)
	{
		if (*s == '\'')
		{
			*s = '#';
			s++;
			while (*s && *s != '\'')
				s++;
			if (*s == 0)
				break;
			*s = '#';
		}
		if (*s == '\"')
		{
			*s = '%';
			s++;
			while (*s && *s != '\"')
				s++;
			if (*s == 0)
				break;
			*s = '%';
		}
		s++;
	}
	return (s);
}*/
/*int main(char **argv, int argc)
{
	if (need_quote("dsadasds\'as\'ad"))
		printf("ok mate you forgot quote");
	else
		printf("all clear");
	return 0;
}*/
/*char	*quotes(char *str)
{



		return (str);


}*/
