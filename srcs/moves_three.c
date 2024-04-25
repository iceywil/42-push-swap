/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:23:13 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/15 16:35:46 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stacks *stacks, char y_n)
{
	t_stack	*last;
	t_stack	*before_last;

	if (stacks->head_a == NULL || stacks->head_a->next == NULL)
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
	if (y_n == 'y')
		write(1, "rra\n", 4);
	else
		store_into_tab(stacks, "rra\n");
}

void	rrb(t_stacks *stacks, char y_n)
{
	t_stack	*last;
	t_stack	*before_last;

	if (stacks->head_b == NULL || stacks->head_b->next == NULL)
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
	if (y_n == 'y')
		write(1, "rrb\n", 4);
	else
		store_into_tab(stacks, "rrb\n");
}

void	rrr_of_a(t_stacks *stacks)
{
	t_stack	*last;
	t_stack	*before_last;

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

void	rrr(t_stacks *stacks, char y_n)
{
	if (stacks->head_a == NULL || stacks->head_a->next == NULL
		|| stacks->head_b == NULL || stacks->head_b->next == NULL)
		return ;
	rrr_of_a(stacks);
	rrr_of_b(stacks);
	if (y_n == 'y')
		write(1, "rrr\n", 4);
	else
		store_into_tab(stacks, "rrr\n");
}
