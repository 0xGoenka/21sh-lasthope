/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfnd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 09:56:15 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/01 09:59:01 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strfnd(char *s, char c)
{
	int r;

	r = 0;
	while (s[r])
	{
		if (s[r] == c)
			return (r);
		r++;
	}
	return (-1);
}