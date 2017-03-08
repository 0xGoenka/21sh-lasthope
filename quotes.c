/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 00:30:02 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/09 00:27:24 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*quotes(t_hist *hist,char *str)
{
	char *s1;
	char *s2;

	if (!need_quote(str) || hist->status)
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
