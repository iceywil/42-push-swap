/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:08:12 by wscherre          #+#    #+#             */
/*   Updated: 2024/02/12 20:22:10 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INTMAX 2147483647
# define INTMIN -2147483648

# include "../libft/libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_tab
{
	char			*text;
	struct s_tab	*next;
}					t_tab;

typedef struct s_values
{
	int				max_a;
	int				min_a;
	int				max_b;
	int				min_b;
}					t_values;

typedef struct s_mov_cheap
{
	int				cost;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_mov_cheap;

typedef struct s_stacks
{
	t_stack			*head_a;
	t_stack			*head_b;
	t_values		*values;
	t_mov_cheap		*cheap;
	t_mov_cheap		*cheap_two;
	t_tab			*tab_a;
	t_tab			*tab_b;
}					t_stacks;

// ERROR CHECKS
void				check_integers(char **argv);
void				check_int_size(char **argv);
void				check_for_doubles(t_stack *head_a);
void				print_error_and_exit(void);
void				check_inputs(int argc, char **argv);
int					is_sorted(t_stacks *stacks);

// FREE
void				free_all(t_stacks *stacks);
void				free_node(t_stack **lst);
void				free_values(t_stacks *stacks);
void				free_cheaps(t_stacks *stacks);
void				free_tabs(t_stacks *stacks);
void				free_tab(t_tab **tab);

// LIST A
t_stack				*create_list_a(int argc, char **argv);
t_stack				*list_a_add_args(char **argv);
t_stack				*list_a_add_str(char **splt);
t_stack				*create_new_node(char **splt, t_stack *new_node,
						t_stack *head_a);
// BRUTE
void				print_set(t_stacks *stacks);
void				run_all_sets(t_stacks *stacks, int argc, char **argv);
void				store_into_tab(t_stacks *stacks, char *action);
void				brute_algo(t_stacks *stacks, int i);
t_tab				*create_tab_node(t_stacks *stacks, char *action);
int					tab_contains_x(t_stacks *stacks);

// STACK UTILS
int					stack_len(t_stack *head_a);
int					tab_len(t_tab *tab);

// SORT IT
void				sort_it(t_stacks *stacks, int i);
void				push_all_a_except_three(t_stacks *stacks);
void				push_back_all_b(t_stacks *stacks);
void				sort_last_a(t_stacks *stacks);

// CHECK CHEAP MOVE
void				check_costs_a_to_b(t_stacks *stacks, t_stack *head);
void				check_costs_b_to_a(t_stacks *stacks, t_stack *head);
void				check_mirror_moves(t_stacks *stacks);

// RUN CHEAP MOVES
void				run_cheap_a_to_b(t_stacks *stacks);
void				run_cheap_a_to_b_two(t_stacks *stacks);
void				run_cheap_b_to_a(t_stacks *stacks);
void				run_cheap_b_to_a_two(t_stacks *stacks);

// COSTS A TO B
void				cost_a_to_b(t_stacks *stacks, t_mov_cheap *cheap,
						t_stack *head);
void				cost_a_to_top(t_stacks *stacks, t_mov_cheap *cheap,
						t_stack *head);
void				new_max_min_a_to_b(t_stacks *stacks, t_mov_cheap *cheap);
void				normal_num_cost_a_to_b(t_stacks *stacks, t_mov_cheap *cheap,
						t_stack *head);

// COSTS B TO A
void				cost_b_to_a(t_stacks *stacks, t_mov_cheap *cheap,
						t_stack *head);
void				cost_b_to_top(t_stacks *stacks, t_mov_cheap *cheap,
						t_stack *head);
void				new_max_min_b_to_a(t_stacks *stacks, t_mov_cheap *cheap);
void				normal_num_cost_b_to_a(t_stacks *stacks, t_mov_cheap *cheap,
						t_stack *head);

// COSTS UTILS
int					find_closest_below_num_index(t_stack *head,
						t_stack *head_cheap);
int					find_num_index(t_stack *head, int num);

// VALUES
void				create_values(t_stacks *stacks);
void				update_values(t_stacks *stacks);
void				update_values_a(t_stacks *stacks);
void				update_values_b(t_stacks *stacks);

// CHEAPS
void				create_cheaps(t_stacks *stacks);
void				copy_cheap(t_mov_cheap *cheap_dest, t_mov_cheap *cheap_src);
void				reset_cheap(t_mov_cheap *cheap);

// ALGOS
void				algo_two(t_stacks *stacks);
void				algo_three_a(t_stacks *stacks);
void				algo_three_b(t_stacks *stacks);
void				algo_four(t_stacks *stacks);

// MOVES
void				pa(t_stacks *stacks, char y_n);
void				pb(t_stacks *stacks, char y_n);
void				sa(t_stacks *stacks, char y_n);
void				sb(t_stacks *stacks, char y_n);
void				ss(t_stacks *stacks, char y_n);
void				ra(t_stacks *stacks, char y_n);
void				rb(t_stacks *stacks, char y_n);
void				rr_of_a(t_stacks *stacks);
void				rr_of_b(t_stacks *stacks);
void				rr(t_stacks *stacks, char y_n);
void				rra(t_stacks *stacks, char y_n);
void				rrb(t_stacks *stacks, char y_n);
void				rrr_of_a(t_stacks *stacks);
void				rrr_of_b(t_stacks *stacks);
void				rrr(t_stacks *stacks, char y_n);

#endif