/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:36:40 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/06 16:38:19 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include "limits.h"

# define true 1
# define false 0
# define DEF "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define BOLD_RED "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_YELLOW "\033[1;33m"
# define BOLD_BLUE "\033[1;34m"
# define BOLD_PURPLE "\033[1;35m"
# define BOLD_CYAN "\033[1;36m"
# define BOLD_WHITE "\033[1;37m"

typedef unsigned char bool;

/*
	a stack is a linked list.
	this structure defines the stack nodes
		  val : value sored in this node
		  pos : pos° in the sack (0 is top)
	top_price : n° of op° to put this node on top of the stack
   push_price : for stack B, n° of op° to put on stack A at the correct pos°
  fst_to_push : for stack B, ptr to the cheapest node to push to A
	   to_rev : true if the op° needed to put on top is rr(a/b) rather than r(a/b)
		 targ : for stack B, ptr to the node in A wich needs to be directly under it
		 next : ptr to the next node of the stack, NULL if there isn't a node above	
		 prev : ptr to the previous node of the stack, NULL if there isn't a node under	
*/
typedef struct s_stack
{
	int				val;
	int				pos;
	int				rev_pos;
	int				push_price;
	bool			to_rev;
	struct s_stack	*fst_to_push;
	struct s_stack	*targ;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*  Utilities  */
void	exit_handler(char *msg);
int		max(int i, int j);
int		min(int i, int j);

/*  Stack related functions  */
t_stack	*init_stack(int ac, char **av);
t_stack	*create_node(long int value);
void	push_node(t_stack **a, t_stack *node);
void	print_stacks(t_stack *a, t_stack *b);
t_stack	*get_biggest(t_stack *stack);
t_stack	*get_top(t_stack *a);
t_stack	*get_smallest(t_stack *a);
t_stack	*get_top2(t_stack *a);
t_stack	*pop(t_stack **a);
int		get_stack_len(t_stack *s);
t_stack	*get_i(t_stack *s, int i);
bool	is_sorted(t_stack *a);
void	free_stack(t_stack **s);
bool	is_biggest(t_stack *e, t_stack *a);
bool	is_smallest(t_stack *e, t_stack *a);
t_stack	*get_smallest_bigger(t_stack *s, int val);
void	node_refresh(t_stack *a, t_stack *b);

/*  Operations  */
/* stack a      */
void	sa(t_stack **a, bool print);
void	pa(t_stack **a, t_stack **b, bool print);
void	ra(t_stack **a, bool print);
void	rra(t_stack **a, bool print);
/* stack b      */
void	sb(t_stack **b, bool print);
void	pb(t_stack **b, t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rrb(t_stack **b, bool print);
/* both stacks  */
void	ss(t_stack **a, t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);

/*  Sorting Algorithms  */
void	sort_shmol(t_stack **a);
void	calc_prices(t_stack *a, t_stack *b);
void	push_swap(t_stack **a, t_stack **b);
t_stack	*rev(t_stack *e);

#endif