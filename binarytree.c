/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarytree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:04:39 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/15 17:51:18 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		tree_exec(t_tree *tree, char *str, t_env *env)
{
	//char *tmp;

	if (tree == NULL)
		return ;
	if (tree->type == 0)
	{
		parser(tree->str, env);
			//ft_strdel(&tmp);
		//if (!tmp)
		
		ft_strdel(&tree->str);
	}
	tree_exec(tree->left, str, env);
	tree_exec(tree->right, str, env);
}

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
	{
		tree->str = parse_quote(str);

	}
	else
	{
		tree->str = NULL;
		tree->left = fill_tree(ft_strndup(str, find_next(str)));
		tree->right = fill_tree(ft_strdup(str + find_next(str) + 1));
		ft_strdel(&str);
	}
	return (tree);
}

void		tree_clean(t_tree *tree)
{
			if (!tree)
				return ;
			ft_strdel(&tree->str);
		
			tree_clean(tree->left);
			tree_clean(tree->right);
			if (tree)
			free(tree);
			tree = NULL;
}

int			find_next(char *str)
{
	if (ft_strchrskipquote(str, ';'))
		return (ft_strchrskipquote(str, ';') - str);
	return (ft_strchrskipquote(str, '|') - str);
}

int			type_cmd(char *str)
{
	if (ft_strchrskipquote(str, ';'))
		return (1);
	if (ft_strchrskipquote(str, '|'))
		return (2);
	return (0);
}

char		*ft_strchrskipquote(char *s, char c)
{
	char d;

	if (!s)
		return (NULL);
	while (*s != c)
	{
		if (*s == 0)
			return (NULL);
		if (*s == '\'' || *s == '\"')
		{
			d = *s;
			s++;
			while (*s != d)
				s++;
		}
		s++;
	}
	return (s);
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
