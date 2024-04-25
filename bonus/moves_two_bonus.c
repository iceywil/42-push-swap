/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:23:13 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/30 16:00:17 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	ra(t_stacks *stacks)
{
	t_stack	*t_two;
	t_stack	*tmp;
	t_stack	*last;

	if (stacks->head_a == NULL)
		return (1);
	if (stacks->head_a->next == NULL)
		return (0);
	t_two = stacks->head_a->next;
	tmp = stacks->head_a;
	while (tmp)
	{
		last = tmp;
		tmp = tmp->next;
	}
	stacks->head_a->next = NULL;
	last->next = stacks->head_a;
	stacks->head_a = t_two;
	return (0);
}

int	rb(t_stacks *stacks)
{
	t_stack	*t_two;
	t_stack	*tmp;
	t_stack	*last;

	if (stacks->head_b == NULL)
		return (1);
	if (stacks->head_b->next == NULL)
		return (0);
	t_two = stacks->head_b->next;
	tmp = stacks->head_b;
	while (tmp)
	{
		last = tmp;
		tmp = tmp->next;
	}
	stacks->head_b->next = NULL;
	last->next = stacks->head_b;
	stacks->head_b = t_two;
	return (0);
}

void	rr_of_a(t_stacks *stacks)
{
	t_stack	*t_two;
	t_stack	*tmp;
	t_stack	*last;

	if (stacks->head_a->next == NULL)
		return ;
	t_two = stacks->head_a->next;
	tmp = stacks->head_a;
	last = NULL;
	while (tmp)
	{
		last = tmp;
		tmp = tmp->next;
	}
	stacks->head_a->next = NULL;
	last->next = stacks->head_a;
	stacks->head_a = t_two;
}

void	rr_of_b(t_stacks *stacks)
{
	t_stack	*t_two;
	t_stack	*tmp;
	t_stack	*last;

	if (stacks->head_b->next == NULL)
		return ;
	t_two = stacks->head_b->next;
	tmp = stacks->head_b;
	last = NULL;
	while (tmp != NULL)
	{
		last = tmp;
		tmp = tmp->next;
	}
	stacks->head_b->next = NULL;
	last->next = stacks->head_b;
	stacks->head_b = t_two;
}

int	rr(t_stacks *stacks)
{
	if (stacks->head_a == NULL || stacks->head_b == NULL)
		return (1);
	rr_of_a(stacks);
	rr_of_b(stacks);
	return (0);
}
