/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:16:06 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/12 18:13:46 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_values(t_stacks *stacks)
{
	t_values	*values;

	values = malloc(sizeof(t_values));
	if (!values)
	{
		free_all(stacks);
		print_error_and_exit();
	}
	values->max_a = 0;
	values->min_a = 0;
	values->max_b = 0;
	values->min_b = 0;
	stacks->values = values;
}

void	update_values_a(t_stacks *stacks)
{
	t_stack	*tmp;
	int		max;
	int		min;

	tmp = stacks->head_a;
	max = INTMIN;
	min = INTMAX;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	stacks->values->max_a = max;
	stacks->values->min_a = min;
}

void	update_values_b(t_stacks *stacks)
{
	t_stack	*tmp;
	int		max;
	int		min;

	tmp = stacks->head_b;
	max = INTMIN;
	min = INTMAX;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	stacks->values->max_b = max;
	stacks->values->min_b = min;
}

void	update_values(t_stacks *stacks)
{
	update_values_a(stacks);
	update_values_b(stacks);
}
