/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:01:05 by jde-meo           #+#    #+#             */
/*   Updated: 2023/12/19 16:20:50 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static long int	ft_atoi2(char *str)
{
	int			i;
	long int	signe;
	long int	nbr;

	i = 0;
	signe = 1;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		exit_handler("Wrong arguments");
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - '0');
	if (str[i] != '\0')
		exit_handler("Wrong arguments");
	return (nbr * signe);
}

void	check_dup(t_stack *s)
{
	t_stack	*a;

	while (s)
	{
		a = s->next;
		while (a)
		{
			if (s->val == a->val)
				exit_handler("Values must be unique");
			a = a->next;
		}
		s = s->next;
	}
}

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack;
	char	**args;
	int		i;

	stack = NULL;
	args = NULL;
	i = 0;
	if (ac < 2 || av[1][0] == '\0')
		exit_handler("Not enough arguments");
	else if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	if (args == NULL)
		exit_handler("Alloc error");
	while (args && args[i] != NULL)
	{
		push_node(&stack, create_node(ft_atoi2(args[i])));
		ra(&stack, FALSE);
		i++;
	}
	if (ac == 2 && args)
		ft_free_split(args);
	check_dup(stack);
	return (stack);
}
