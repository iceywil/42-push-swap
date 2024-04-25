/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:02:51 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/16 18:20:57 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stacks *stacks, char y_n)
{
	t_stack	*new_a;

	if (stacks->head_b == NULL)
		return ;
	new_a = stacks->head_b;
	if (stacks->head_b->next)
		stacks->head_b = stacks->head_b->next;
	else
		stacks->head_b = NULL;
	new_a->next = stacks->head_a;
	stacks->head_a = new_a;
	if (y_n == 'y')
		write(1, "pa\n", 3);
	else
		store_into_tab(stacks, "pa\n");
}

void	pb(t_stacks *stacks, char y_n)
{
	t_stack	*new_b;

	if (stacks->head_a == NULL)
		return ;
	new_b = stacks->head_a;
	if (stacks->head_a->next)
		stacks->head_a = stacks->head_a->next;
	else
		stacks->head_a = NULL;
	new_b->next = stacks->head_b;
	stacks->head_b = new_b;
	if (y_n == 'y')
		write(1, "pb\n", 3);
	else
		store_into_tab(stacks, "pb\n");
}

void	sa(t_stacks *stacks, char y_n)
{
	t_stack	*t_one;
	t_stack	*t_two;

	if (stacks->head_a == NULL || stacks->head_a->next == NULL)
		return ;
	t_one = stacks->head_a;
	t_two = t_one->next;
	t_one->next = t_two->next;
	t_two->next = t_one;
	stacks->head_a = t_two;
	if (y_n == 'y')
		write(1, "sa\n", 3);
	else
		store_into_tab(stacks, "sa\n");
}

void	sb(t_stacks *stacks, char y_n)
{
	t_stack	*t_one;
	t_stack	*t_two;

	if (stacks->head_b == NULL || stacks->head_b->next == NULL)
		return ;
	t_one = stacks->head_b;
	t_two = t_one->next;
	t_one->next = t_two->next;
	t_two->next = t_one;
	stacks->head_b = t_two;
	if (y_n == 'y')
		write(1, "sb\n", 3);
	else
		store_into_tab(stacks, "sb\n");
}

void	ss(t_stacks *stacks, char y_n)
{
	t_stack	*t_one;
	t_stack	*t_two;

	if (stacks->head_a == NULL || stacks->head_a->next == NULL
		|| stacks->head_b == NULL || stacks->head_b->next == NULL)
		return ;
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
	if (y_n == 'y')
		write(1, "ss\n", 3);
	else
		store_into_tab(stacks, "ss\n");
}
