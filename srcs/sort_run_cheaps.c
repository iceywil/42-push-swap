/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_run_cheaps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:21:01 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/16 18:21:41 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	run_cheap_a_to_b_two(t_stacks *stacks)
{
	while (stacks->cheap->ra > 0)
	{
		ra(stacks, 'n');
		stacks->cheap->ra--;
	}
	while (stacks->cheap->rra > 0)
	{
		rra(stacks, 'n');
		stacks->cheap->rra--;
	}
	while (stacks->cheap->rr > 0)
	{
		rr(stacks, 'n');
		stacks->cheap->rr--;
	}
}

void	run_cheap_a_to_b(t_stacks *stacks)
{
	run_cheap_a_to_b_two(stacks);
	while (stacks->cheap->rb > 0)
	{
		rb(stacks, 'n');
		stacks->cheap->rb--;
	}
	while (stacks->cheap->rrb > 0)
	{
		rrb(stacks, 'n');
		stacks->cheap->rrb--;
	}
	while (stacks->cheap->rrr > 0)
	{
		rrr(stacks, 'n');
		stacks->cheap->rrr--;
	}
	pb(stacks, 'n');
}

void	run_cheap_b_to_a_two(t_stacks *stacks)
{
	while (stacks->cheap->ra > 0)
	{
		ra(stacks, 'n');
		stacks->cheap->ra--;
	}
	while (stacks->cheap->rra > 0)
	{
		rra(stacks, 'n');
		stacks->cheap->rra--;
	}
	while (stacks->cheap->rr > 0)
	{
		rr(stacks, 'n');
		stacks->cheap->rr--;
	}
}

void	run_cheap_b_to_a(t_stacks *stacks)
{
	run_cheap_b_to_a_two(stacks);
	while (stacks->cheap->rb > 0)
	{
		rb(stacks, 'n');
		stacks->cheap->rb--;
	}
	while (stacks->cheap->rrb > 0)
	{
		rrb(stacks, 'n');
		stacks->cheap->rrb--;
	}
	while (stacks->cheap->rrr > 0)
	{
		rrr(stacks, 'n');
		stacks->cheap->rrr--;
	}
	pa(stacks, 'n');
}
