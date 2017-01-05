/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 16:14:26 by eleclet           #+#    #+#             */
/*   Updated: 2016/09/06 18:49:06 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GARBAGE_H
# define FT_GARBAGE_H



typedef struct		s_garbage
{
	//int 		id;
	//t_node		*node;
	void *p;
	struct s_garbage	*next;
}			t_garbage;
void	gc_free(void);
void	*gc_alloc(size_t size);
void	*gc_add(void *p);

t_garbage	*gc;
t_garbage	*current_gc;


/*typedef struct		s_node
{
	void *p;
	struct s_node	*next;
}			t_node;
*/


#endif
