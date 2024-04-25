/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:19:30 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/16 18:22:06 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_it(t_stacks *stacks, int i)
{
	if (stack_len(stacks->head_a) == 1)
		return ;
	else if (stack_len(stacks->head_a) == 2)
		algo_two(stacks);
	else if (stack_len(stacks->head_a) == 3)
		algo_three_a(stacks);
	else if (stack_len(stacks->head_a) == 4)
		algo_four(stacks);
	else
	{
		brute_algo(stacks, i);
		i = 0;
		pb(stacks, 'n');
		pb(stacks, 'n');
		create_values(stacks);
		create_cheaps(stacks);
		push_all_a_except_three(stacks);
		algo_three_a(stacks);
		push_back_all_b(stacks);
		sort_last_a(stacks);
		store_into_tab(stacks, "x");
	}
}

void	push_all_a_except_three(t_stacks *stacks)
{
	while (stack_len(stacks->head_a) > 3)
	{
		update_values(stacks);
		check_costs_a_to_b(stacks, stacks->head_a);
		check_mirror_moves(stacks);
		run_cheap_a_to_b(stacks);
		reset_cheap(stacks->cheap);
		reset_cheap(stacks->cheap_two);
	}
}

void	check_costs_a_to_b(t_stacks *stacks, t_stack *head)
{
	while (head)
	{
		if (stacks->cheap->cost == 0)
			cost_a_to_b(stacks, stacks->cheap, head);
		else
			cost_a_to_b(stacks, stacks->cheap_two, head);
		if ((stacks->cheap->cost > stacks->cheap_two->cost
				&& stacks->cheap_two->cost != 0))
			copy_cheap(stacks->cheap, stacks->cheap_two);
		reset_cheap(stacks->cheap_two);
		head = head->next;
	}
}

void	push_back_all_b(t_stacks *stacks)
{
	while (stacks->head_b)
	{
		update_values(stacks);
		check_costs_b_to_a(stacks, stacks->head_b);
		check_mirror_moves(stacks);
		run_cheap_b_to_a(stacks);
		reset_cheap(stacks->cheap);
		reset_cheap(stacks->cheap_two);
	}
}

void	sort_last_a(t_stacks *stacks)
{
	t_stack	*tmp;
	int		head_len;
	int		i;

	update_values(stacks);
	tmp = stacks->head_a;
	head_len = stack_len(stacks->head_a);
	if (stacks->head_a->value != stacks->values->min_a)
	{
		i = find_num_index(stacks->head_a, stacks->values->max_a);
		if (i < head_len - i)
		{
			i++;
			while (i-- > 0)
				ra(stacks, 'n');
		}
		else
		{
			i = head_len - i - 1;
			while (i-- > 0)
				rra(stacks, 'n');
		}
	}
}
