/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_costs_a_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:21:01 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/16 18:19:43 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	cost_a_to_b(t_stacks *stacks, t_mov_cheap *cheap, t_stack *head)
{
	cost_a_to_top(stacks, cheap, head);
	if (head->value < stacks->values->min_b
		|| head->value > stacks->values->max_b)
		new_max_min_a_to_b(stacks, cheap);
	else
		normal_num_cost_a_to_b(stacks, cheap, head);
}

void	cost_a_to_top(t_stacks *stacks, t_mov_cheap *cheap, t_stack *head)
{
	int	i;
	int	head_len;

	head_len = stack_len(stacks->head_a);
	i = find_num_index(stacks->head_a, head->value);
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

void	new_max_min_a_to_b(t_stacks *stacks, t_mov_cheap *cheap)
{
	int	i;
	int	head_len;

	cheap->cost += 1;
	cheap->pb = 1;
	head_len = stack_len(stacks->head_b);
	i = find_num_index(stacks->head_b, stacks->values->max_b);
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

void	normal_num_cost_a_to_b(t_stacks *stacks, t_mov_cheap *cheap,
		t_stack *head)
{
	int	i;
	int	head_len;

	cheap->cost += 1;
	cheap->pb = 1;
	head_len = stack_len(stacks->head_b);
	i = find_closest_below_num_index(stacks->head_b, head);
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

int	find_closest_below_num_index(t_stack *head, t_stack *head_cheap)
{
	int		cheap_value;
	int		i;

	i = -1;
	cheap_value = head_cheap->value;
	while (1)
	{
		cheap_value++;
		i = find_num_index(head, cheap_value);
		if (i >= 0)
			return (i + 1);
	}
	return (0);
}
