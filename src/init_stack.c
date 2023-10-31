/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:01:05 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/31 00:43:11 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_atoi2(char *str)
{
	int		i;
	int		signe;
	int		nbr;

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

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack;
	char	**args;
	int		i;
	
	stack = NULL;
	i = 0;
	if (ac < 2 || av[1][0] == '\0')
		exit_handler("Wrong arguments");
	else if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	while (args && args[i] != NULL)
	{
		push_node(&stack, create_node(ft_atoi2(args[i])));
		i++;
	}
	if (ac == 2 && args)
		ft_free_split(args);
	return (stack);
}
