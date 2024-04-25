/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:23:13 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/30 16:01:20 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	rra(t_stacks *stacks)
{
	t_stack	*last;
	t_stack	*before_last;

	if (stacks->head_a == NULL)
		return (1);
	if (stacks->head_a->next == NULL)
		return (0);
	last = stacks->head_a;
	before_last = NULL;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = stacks->head_a;
	stacks->head_a = last;
	return (0);
}

int	rrb(t_stacks *stacks)
{
	t_stack	*last;
	t_stack	*before_last;

	if (stacks->head_b == NULL)
		return (1);
	if (stacks->head_b->next == NULL)
		return (0);
	last = stacks->head_b;
	before_last = NULL;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = stacks->head_b;
	stacks->head_b = last;
	return (0);
}

void	rrr_of_a(t_stacks *stacks)
{
	t_stack	*last;
	t_stack	*before_last;

	if (stacks->head_a->next == NULL)
		return ;
	last = stacks->head_a;
	before_last = NULL;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = stacks->head_a;
	stacks->head_a = last;
}

void	rrr_of_b(t_stacks *stacks)
{
	t_stack	*last;
	t_stack	*before_last;

	if (stacks->head_b->next == NULL)
		return ;
	last = stacks->head_b;
	before_last = NULL;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = stacks->head_b;
	stacks->head_b = last;
}

int	rrr(t_stacks *stacks)
{
	if (stacks->head_a == NULL || stacks->head_b == NULL)
		return (1);
	rrr_of_a(stacks);
	rrr_of_b(stacks);
	return (0);
}
