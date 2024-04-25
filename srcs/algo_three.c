/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:19:30 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/17 18:38:18 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algo_three_a(t_stacks *stacks)
{
	int	t_one;
	int	t_two;
	int	t_three;

	t_one = stacks->head_a->value;
	t_two = stacks->head_a->next->value;
	t_three = stacks->head_a->next->next->value;
	if (t_one > t_two && t_one > t_three)
	{
		if (t_two > t_three)
		{
			sa(stacks, 'n');
			rra(stacks, 'n');
		}
		else
			ra(stacks, 'n');
	}
	else
		algo_three_b(stacks);
}

void	algo_three_b(t_stacks *stacks)
{
	int	t_one;
	int	t_two;
	int	t_three;

	t_one = stacks->head_a->value;
	t_two = stacks->head_a->next->value;
	t_three = stacks->head_a->next->next->value;
	if (t_one < t_two && t_one < t_three && t_two > t_three)
	{
		rra(stacks, 'n');
		sa(stacks, 'n');
	}
	else if (t_one < t_two && t_two > t_three)
		rra(stacks, 'n');
	else if (t_one > t_two)
		sa(stacks, 'n');
}
