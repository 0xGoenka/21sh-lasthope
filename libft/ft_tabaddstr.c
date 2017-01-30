/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabaddstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:43:57 by eleclet           #+#    #+#             */
/*   Updated: 2017/01/30 19:02:47 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabaddstr(char **src, char *str)
{
	char **r;
	int len;

	len = ft_tablen(src);

	r = (char **)malloc(sizeof(char *) * (len + 2));
	r[len + 1] = NULL;
	r[len] = ft_strdup(str);
	while (--len >= 0)
		r[len] = ft_strdup(src[len]);

	if (src && *src)
		ft_tabdel(src);
	return (r);
}
