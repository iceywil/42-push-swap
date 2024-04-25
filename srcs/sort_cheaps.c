/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cheaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:16:06 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/11 16:49:44 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_cheaps(t_stacks *stacks)
{
	t_mov_cheap	*cheap;
	t_mov_cheap	*cheap_two;

	cheap = malloc(sizeof(t_mov_cheap));
	if (!cheap)
	{
		free_all(stacks);
		print_error_and_exit();
	}
	stacks->cheap = cheap;
	cheap_two = malloc(sizeof(t_mov_cheap));
	if (!cheap_two)
	{
		free_all(stacks);
		print_error_and_exit();
	}
	stacks->cheap_two = cheap_two;
	reset_cheap(cheap);
	reset_cheap(cheap_two);
}

void	copy_cheap(t_mov_cheap *cheap_dest, t_mov_cheap *cheap_src)
{
	cheap_dest->cost = cheap_src->cost;
	cheap_dest->sa = cheap_src->sa;
	cheap_dest->sb = cheap_src->sb;
	cheap_dest->ss = cheap_src->ss;
	cheap_dest->pa = cheap_src->pa;
	cheap_dest->pb = cheap_src->pb;
	cheap_dest->ra = cheap_src->ra;
	cheap_dest->rb = cheap_src->rb;
	cheap_dest->rr = cheap_src->rr;
	cheap_dest->rra = cheap_src->rra;
	cheap_dest->rrb = cheap_src->rrb;
	cheap_dest->rrr = cheap_src->rrr;
}

void	reset_cheap(t_mov_cheap *cheap)
{
	cheap->cost = 0;
	cheap->sa = 0;
	cheap->sb = 0;
	cheap->ss = 0;
	cheap->pa = 0;
	cheap->pb = 0;
	cheap->ra = 0;
	cheap->rb = 0;
	cheap->rr = 0;
	cheap->rra = 0;
	cheap->rrb = 0;
	cheap->rrr = 0;
}
