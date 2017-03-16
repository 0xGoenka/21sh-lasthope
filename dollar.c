/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:34:21 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/16 18:54:26 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_repdol(char *cmd, char *tabvar, int pos, int lenvar)
{
	char *r;
	int cmdlen;

	cmdlen = ft_strlen(cmd);
	r = malloc(sizeof(char) * (cmdlen - lenvar + ft_strlen(tabvar) + 1));
	r[cmdlen - lenvar + ft_strlen(tabvar)] = 0;
	ft_strncpy(r, cmd, pos);
	ft_strncpy(r + pos, tabvar, ft_strlen(tabvar));
	ft_strcpy(r + pos + ft_strlen(tabvar), cmd + pos + lenvar);
	ft_strdel(&cmd);
	return (r);
}
