/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:38:23 by wscherre          #+#    #+#             */
/*   Updated: 2024/02/12 20:19:33 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc > 1)
	{
		check_inputs(argc, argv);
		stacks.head_b = NULL;
		stacks.values = NULL;
		stacks.cheap = NULL;
		stacks.cheap_two = NULL;
		stacks.tab_a = NULL;
		stacks.tab_b = NULL;
		run_all_sets(&stacks, argc, argv);
		print_set(&stacks);
		free_all(&stacks);
		free_tabs(&stacks);
	}
	return (0);
}

int	is_sorted(t_stacks *stacks)
{
	t_stack	*tmp;
	int		is_sorted;

	is_sorted = 0;
	tmp = stacks->head_a;
	while (tmp)
	{
		if (tmp->next && tmp->value > tmp->next->value)
			is_sorted = 1;
		tmp = tmp->next;
	}
	if (is_sorted == 1)
		return (0);
	return (1);
}
