/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 15:58:24 by eleclet           #+#    #+#             */
/*   Updated: 2016/09/06 18:35:44 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*gc_add(void *p)
{	
	if (gc == NULL)
	{
		gc = (t_garbage *)malloc(sizeof(t_garbage));
		gc->next = NULL;
		gc->p = p;
		current_gc = gc;
		return (p);
	}
	current_gc->next = (t_garbage *)malloc(sizeof(t_garbage));
	current_gc = current_gc->next;
	current_gc->p = p;
	current_gc->next = NULL;
	return (p);
}
void	*gc_alloc(size_t size)
{
	void *p = malloc(sizeof(size));

	if (gc == NULL)
	{
		gc = (t_garbage *)malloc(sizeof(t_garbage));
		gc->next = NULL;
		gc->p = p;
		current_gc = gc;
		return (p);
	}
	current_gc->next = (t_garbage *)malloc(sizeof(t_garbage));
	current_gc = current_gc->next;
	current_gc->p = p;
	current_gc->next = NULL;
	return (p);
}

void	gc_free(void)
{
	t_garbage *copy;
	while (gc)
	{
		free(gc->p);
		gc->p = NULL;
		copy = gc;
		gc = gc->next;
		free(copy);
		copy = NULL;
		
	}
}

/*bool	id_exist(int id, t_lst *lst)
{
	bool b;

	b = 0;
	while (lst)
	{
		if (id == lst->id)
		{
			b = 1;
			break;
		}
		lst = lst->next;
	}
	return (b);
}*/


