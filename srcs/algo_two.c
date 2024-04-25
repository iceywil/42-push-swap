/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:20:00 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/15 17:48:34 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algo_two(t_stacks *stacks)
{
	t_stack	*t_one;

	t_one = stacks->head_a;
	if (t_one->value > t_one->next->value)
		sa(stacks, 'n');
}
