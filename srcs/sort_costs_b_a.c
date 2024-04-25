/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_costs_b_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:49:10 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/18 16:51:36 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	cost_b_to_a(t_stacks *stacks, t_mov_cheap *cheap, t_stack *head)
{
	cost_b_to_top(stacks, cheap, head);
	if (head->value < stacks->values->min_a
		|| head->value > stacks->values->max_a)
		new_max_min_b_to_a(stacks, cheap);
	else
		normal_num_cost_b_to_a(stacks, cheap, head);
}

void	cost_b_to_top(t_stacks *stacks, t_mov_cheap *cheap, t_stack *head)
{
	int	i;
	int	head_len;

	head_len = stack_len(stacks->head_b);
	i = find_num_index(stacks->head_b, head->value);
	if (i < head_len - i)
	{
		cheap->rb = i;
		cheap->cost += i;
	}
	else
	{
		cheap->rrb = head_len - i;
		cheap->cost += head_len - i;
	}
}

void	new_max_min_b_to_a(t_stacks *stacks, t_mov_cheap *cheap)
{
	int	i;
	int	head_len;

	cheap->cost += 1;
	cheap->pa = 1;
	head_len = stack_len(stacks->head_a);
	i = find_num_index(stacks->head_a, stacks->values->min_a);
	if (i < head_len - i)
	{
		cheap->ra = i;
		cheap->cost += i;
	}
	else
	{
		cheap->rra = head_len - i;
		cheap->cost += head_len - i;
	}
}

void	normal_num_cost_b_to_a(t_stacks *stacks, t_mov_cheap *cheap,
		t_stack *head)
{
	int	i;
	int	head_len;

	cheap->cost += 1;
	cheap->pa = 1;
	head_len = stack_len(stacks->head_a);
	i = find_closest_below_num_index(stacks->head_a, head) - 1;
	if (i < head_len - i)
	{
		cheap->ra = i;
		cheap->cost += i;
	}
	else
	{
		cheap->rra = head_len - i;
		cheap->cost += head_len - i;
	}
}
