/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:23:13 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/15 16:35:55 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stacks *stacks, char y_n)
{
	t_stack	*t_two;
	t_stack	*tmp;
	t_stack	*last;

	if (stacks->head_a == NULL || stacks->head_a->next == NULL)
		return ;
	t_two = stacks->head_a->next;
	tmp = stacks->head_a;
	last = NULL;
	while (tmp != NULL)
	{
		last = tmp;
		tmp = tmp->next;
	}
	stacks->head_a->next = NULL;
	last->next = stacks->head_a;
	stacks->head_a = t_two;
	if (y_n == 'y')
		write(1, "ra\n", 3);
	else
		store_into_tab(stacks, "ra\n");
}

void	rb(t_stacks *stacks, char y_n)
{
	t_stack	*t_two;
	t_stack	*tmp;
	t_stack	*last;

	if (stacks->head_b == NULL || stacks->head_b->next == NULL)
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
	if (y_n == 'y')
		write(1, "rb\n", 3);
	else
		store_into_tab(stacks, "rb\n");
}

void	rr_of_a(t_stacks *stacks)
{
	t_stack	*t_two;
	t_stack	*tmp;
	t_stack	*last;

	t_two = stacks->head_a->next;
	tmp = stacks->head_a;
	last = NULL;
	while (tmp != NULL)
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

void	rr(t_stacks *stacks, char y_n)
{
	if (stacks->head_a == NULL || stacks->head_a->next == NULL
		|| stacks->head_b == NULL || stacks->head_b->next == NULL)
		return ;
	rr_of_a(stacks);
	rr_of_b(stacks);
	if (y_n == 'y')
		write(1, "rr\n", 3);
	else
		store_into_tab(stacks, "rr\n");
}
