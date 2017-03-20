/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabrmstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 21:02:07 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/17 12:04:04 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabrmstr(char **t, char *s)
{
	char	**r;
	int		i;

	r = NULL;
	i = 0;
	if (!t || !*t || !s || !*s)
		return (t);
	while (t[i])
	{
		if (strcmp(s, t[i]) != 0)
			r = ft_tabaddstr(r, t[i]);
		i++;
	}
	ft_tabdel(t);
	return (r);
}
