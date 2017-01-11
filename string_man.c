/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_man.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:02:31 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/11 00:06:17 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*s_add(char *s, char c, int pos)
{
	char *r;
	int i;
	int k;
	int len;
	
	k = 0;
	i = 0;
	len = ft_strlen(s) + 1;
	if (pos > ((int)ft_strlen(s) + 1) || pos < 0)
		return (s);
	r = (char *)malloc(sizeof(char) * len + 1);
	r[ft_strlen(s) + 1] = 0;
	while (i < len)
	{
		if (i == pos)
		{
			r[i] = c;
			k = 1;
		}
		r[i + k] = s[i];
		i++;
	}
	return (r);
}

char	*s_del(char *s, int pos)
{
	char *r;
	int len;
	int i;
	int k;
	
	k = 0;
	i = 0;
	len = ft_strlen(s) - 1;
	if (pos < 0 || pos > len)
		return (s);
	r = (char *)malloc(sizeof(char) * len + 1);
	r[len] = 0;
	while (i <= len)
	{
		if (pos == i)
			k = 1;
		
		
			r[i] = s[i + k];
		
		i++;
	}
	return (r);
}
