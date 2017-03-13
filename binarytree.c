/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarytree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:04:39 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/13 18:07:09 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_tree		*fill_tree(char *str)
{
	t_tree *tree;

	tree = NULL;
	if (ft_strlen(str) == 0)
		return (NULL);
	if (tree == NULL)
		tree = malloc(sizeof(t_tree));
	tree->right = NULL;
	tree->left = NULL;
	tree->type = type_cmd(str);
	if (tree->type == 0)
		tree->str = ft_strdup(str);
	else
	{
		tree->str = NULL;
		tree->left = fill_tree(ft_strndup(str, find_next(str)));
		tree->right = fill_tree(ft_strdup(str + find_next(str) + 1));
	}
	return (tree);
}

int			find_next(char *str)
{

	if (ft_strchr(str, ';'))
		return (ft_strchr(str, ';') - str);
	return (ft_strchr(str, '|') - str);
}
int			type_cmd(char *str)
{
			if (ft_strchr(str, ';'))
				return (1);
			if (ft_strchr(str, '|'))
				return (2);
			return (0);
}

void		read_tree(t_tree *tree)
{
		if (tree == NULL)
			return ;
		if (tree->type == 0)
			ft_putendl(tree->str);
		if (tree->type == 1)
			ft_putendl(";");
		if (tree->type == 2)
			ft_putendl("|");
		read_tree(tree->left);
		read_tree(tree->right);
}
