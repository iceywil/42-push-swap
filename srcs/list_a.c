/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:38:23 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/16 21:15:58 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_list_a(int argc, char **argv)
{
	char	**splt;
	t_stack	*head_a;

	head_a = NULL;
	if (argc == 2)
	{
		splt = ft_split(argv[1], ' ');
		head_a = list_a_add_str(splt);
		ft_free_double_tab(&splt);
	}
	else
		head_a = list_a_add_args(argv);
	return (head_a);
}

t_stack	*list_a_add_args(char **argv)
{
	t_stack	*new_node;
	t_stack	*tmp;
	t_stack	*head_a;
	int		y;

	head_a = NULL;
	y = 1;
	tmp = head_a;
	while (argv[y])
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
		{
			free_node(&head_a);
			print_error_and_exit();
		}
		new_node->value = ft_atoi(argv[y++]);
		new_node->next = NULL;
		if (!head_a)
			head_a = new_node;
		else
			tmp->next = new_node;
		tmp = new_node;
	}
	return (head_a);
}

t_stack	*list_a_add_str(char **splt)
{
	t_stack	*new_node;
	t_stack	*head_a;
	t_stack	*tmp;
	int		i;

	head_a = NULL;
	i = 0;
	tmp = head_a;
	while (splt[i])
	{
		new_node = create_new_node(splt, new_node, head_a);
		new_node->value = ft_atoi(splt[i++]);
		new_node->next = NULL;
		if (!head_a)
			head_a = new_node;
		else
			tmp->next = new_node;
		tmp = new_node;
	}
	return (head_a);
}

t_stack	*create_new_node(char **splt, t_stack *new_node, t_stack *head_a)
{
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		free_node(&head_a);
		ft_free_double_tab(&splt);
		print_error_and_exit();
	}
	return (new_node);
}
