/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:02:51 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/30 17:04:39 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	pa(t_stacks *stacks)
{
	t_stack	*new_a;

	if (stacks->head_b == NULL)
		return (1);
	new_a = stacks->head_b;
	if (stacks->head_b->next)
		stacks->head_b = stacks->head_b->next;
	else
		stacks->head_b = NULL;
	new_a->next = stacks->head_a;
	stacks->head_a = new_a;
	return (0);
}

int	pb(t_stacks *stacks)
{
	t_stack	*new_b;

	if (stacks->head_a == NULL)
		return (1);
	new_b = stacks->head_a;
	if (stacks->head_a->next)
		stacks->head_a = stacks->head_a->next;
	else
		stacks->head_a = NULL;
	new_b->next = stacks->head_b;
	stacks->head_b = new_b;
	return (0);
}

int	sa(t_stacks *stacks)
{
	t_stack	*t_one;
	t_stack	*t_two;

	if (stacks->head_a == NULL)
		return (1);
	if (stacks->head_a->next == NULL)
		return (0);
	t_one = stacks->head_a;
	t_two = t_one->next;
	t_one->next = t_two->next;
	t_two->next = t_one;
	stacks->head_a = t_two;
	return (0);
}

int	sb(t_stacks *stacks)
{
	t_stack	*t_one;
	t_stack	*t_two;

	if (stacks->head_b == NULL || stacks->head_b->next == NULL)
		return (1);
	t_one = stacks->head_b;
	t_two = t_one->next;
	t_one->next = t_two->next;
	t_two->next = t_one;
	stacks->head_b = t_two;
	return (0);
}

int	ss(t_stacks *stacks)
{
	t_stack	*t_one;
	t_stack	*t_two;

	if (stacks->head_a == NULL || stacks->head_a->next == NULL
		|| stacks->head_b == NULL || stacks->head_b->next == NULL)
		return (1);
	t_one = stacks->head_a;
	t_two = t_one->next;
	t_one->next = t_two->next;
	t_two->next = t_one;
	stacks->head_a = t_two;
	t_one = stacks->head_b;
	t_two = t_one->next;
	t_one->next = t_two->next;
	t_two->next = t_one;
	stacks->head_b = t_two;
	return (0);
}
