/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:38:23 by wscherre          #+#    #+#             */
/*   Updated: 2024/02/20 18:52:34 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	run_all_sets(t_stacks *stacks, int argc, char **argv)
{
	int	i;
	int	x;

	i = 0;
	while (1)
	{
		x = tab_len(stacks->tab_a);
		stacks->head_a = create_list_a(argc, argv);
		check_for_doubles(stacks->head_a);
		if (is_sorted(stacks))
			return (free_all(stacks), exit(0));
		if (i + 2 > stack_len(stacks->head_a) || (x > 0 && x < 5500))
			return ;
		sort_it(stacks, i);
		if (tab_len(stacks->tab_a) > tab_len(stacks->tab_b)
			&& tab_len(stacks->tab_b) > 0)
		{
			free_tab(&(stacks->tab_a));
			stacks->tab_a = stacks->tab_b;
		}
		else
			free_tab(&(stacks->tab_b));
		stacks->tab_b = NULL;
		(free_all(stacks), i++);
	}
}

void	print_set(t_stacks *stacks)
{
	t_tab	*tmp;

	tmp = stacks->tab_a;
	while (tmp)
	{
		if ((tmp->text)[0] != 'x')
			ft_printf("%s", tmp->text);
		tmp = tmp->next;
	}
}

void	brute_algo(t_stacks *stacks, int i)
{
	if (stack_len(stacks->head_a) - i - 2 > 0)
	{
		while (i > 0)
		{
			ra(stacks, 'n');
			i--;
		}
	}
	else
	{
		while (stack_len(stacks->head_a) - i - 2 > 0)
		{
			rra(stacks, 'n');
			i--;
		}
	}
}

void	store_into_tab(t_stacks *stacks, char *action)
{
	t_tab	*tmp;
	int		i;

	i = 0;
	if (stacks->tab_a)
	{
		if (!tab_contains_x(stacks) || (tab_contains_x(stacks)
				&& stacks->tab_b))
		{
			if (!tab_contains_x(stacks))
				tmp = stacks->tab_a;
			else
				tmp = stacks->tab_b;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = create_tab_node(stacks, action);
		}
		else
		{
			stacks->tab_b = create_tab_node(stacks, action);
		}
	}
	else
		stacks->tab_a = create_tab_node(stacks, action);
}

t_tab	*create_tab_node(t_stacks *stacks, char *action)
{
	t_tab	*node;

	node = malloc(sizeof(t_tab));
	if (!node)
	{
		free_all(stacks);
		print_error_and_exit();
	}
	node->text = action;
	node->next = NULL;
	return (node);
}
