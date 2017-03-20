/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:07:30 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/17 17:09:14 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int     col(void)
{
    struct winsize w;

    ioctl(0, TIOCGWINSZ, &w);
    return (w.ws_col);
}
int     row(void)
{
    struct winsize w;

    ioctl(0, TIOCGWINSZ, &w);
    return (w.ws_row);
}
