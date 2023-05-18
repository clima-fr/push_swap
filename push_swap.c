/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clima-fr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:48:57 by clima-fr          #+#    #+#             */
/*   Updated: 2023/05/17 22:49:01 by clima-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*head_a;

	if (ac < 2)
		return (0);
	else
	{
		head_a = ft_check_arg_and_create_stack_a(ac, av);
		if (!head_a || ft_check_doubles(&head_a) == 1)
		{
			ft_freelst(&head_a);
			ft_error();
		}
		if (!ft_check_sorted(&head_a))
		{
			ft_sort_cases(&head_a);
		}
		ft_freelst(&head_a);
	}
}
