/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_shmol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:48:04 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/31 02:47:27 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_shmol(t_stack **a)
{
	int	len;
	
	if (is_sorted(*a))
		return ;
	len = get_stack_len(*a);
	if (len == 2)
		return sa(a, true);
	if (len != 3)
		return ;
	if (get_top(*a) == get_biggest(*a))
		ra(a, true);
	else if ((*a)->next == get_biggest(*a))
		rra(a, true);
	if (!is_sorted(*a))
		sa(a, true);
}
