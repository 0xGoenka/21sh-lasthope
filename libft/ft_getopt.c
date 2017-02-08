/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:31:07 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/08 16:52:04 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_err(char *s, char c)
{
	ft_putstr(s);
	ft_putstr(" : invalid option -- '");
	ft_putchar(c);
	ft_putendl("'");
}

static char	*ret_opt(char **line, char *allowed, int *status)
{
	char *r;
	int i;
	int j;

	r = NULL;
	i = 0;
	j = 0;
	while (line[++i])
	{
		if (line[i][0] != '-' || ft_strcmp(line[i], "--") == 0)
			break;
		while (line[i][0] && line[i][++j])
		{
			if (!ft_strchr(allowed, line[i][j]))
			{
				print_err(line[0], line[i][j]);
				*status = 1;
				return (NULL);
			}
			else
				r = ft_saddc(r, line[i][j], 0);
		}
		j = 0;
	}
	return (r);
}

static char	**ret_arg(char **line)
{
	int i;
	char **r;

	r = NULL;
	i = 0;
	while (line[++i])
	{
		if (line[i][0] != '-' || ft_strcmp(line[i], "--") == 0)
			break ;
	}
	while (line[i])
	{
		r = ft_tabaddstr(r, line[i]);
		i++;
	}
	return (r);
}

t_opt	ft_getopt(char **line, char *allowed)
{
	t_opt r;
	int status;

	status = 0;

	r.opt = ret_opt(line, allowed, &status);
	r.arg = ret_arg(line);
	r.status = status;
	return (r);
}
