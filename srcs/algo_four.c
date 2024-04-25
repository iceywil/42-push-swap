/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:51:38 by wscherre          #+#    #+#             */
/*   Updated: 2024/02/20 18:51:41 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algo_four(t_stacks *stacks)
{
	int	t_one;
	int	t_two;
	int	t_three;
	int	t_four;

	pb(stacks, 'n');
	algo_three_a(stacks);
	pa(stacks, 'n');
	t_four = stacks->head_a->value;
	t_one = stacks->head_a->next->value;
	t_two = stacks->head_a->next->next->value;
	t_three = stacks->head_a->next->next->next->value;
	if (t_four > t_one && t_four < t_two)
		sa(stacks, 'n');
	else if (t_four > t_two && t_four < t_three)
	{
		rra(stacks, 'n');
		sa(stacks, 'n');
		ra(stacks, 'n');
		ra(stacks, 'n');
	}
	else if (t_four > t_three)
		ra(stacks, 'n');
}
