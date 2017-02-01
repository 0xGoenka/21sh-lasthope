/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 21:56:23 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/31 22:22:09 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tabchr(char **tab, char *s)
{
	int r;

	r = 0;
	if (!tab)
		return (-1);
	while (tab[r])
	{
		if (ft_strncmp(tab[r], s, ft_strlen(s)) == 0)
			return (r);
		r++;
	}
	return (-1);
}
