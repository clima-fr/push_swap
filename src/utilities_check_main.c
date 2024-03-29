/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_check_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clima-fr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:49:42 by clima-fr          #+#    #+#             */
/*   Updated: 2023/05/17 22:49:45 by clima-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void	ft_create_node(t_stack **head, char *str)
{
	int	numb;

	numb = ft_atoi(str);
	ft_lstadd_back(head, ft_lstnew(numb));
}

t_stack	*ft_arg_to_split(char **split)
{
	t_stack	*head_a;
	int		i;

	head_a = NULL;
	if (*split == NULL || split == NULL)
	{	
		ft_freesplit(split);
		free(split);
		exit (0);
	}
	i = 0;
	while (split[i])
	{
		ft_create_node(&head_a, split[i]);
		i++;
	}
	return (head_a);
}

t_stack	*ft_check_arg_and_create_stack_a(int ac, char **av)
{
	t_stack	*head_a;
	char	**split;
	int		i;

	head_a = NULL;
	if (ac == 2)
	{
		split = ft_split(av[1], 32);
		head_a = ft_arg_to_split(split);
		ft_freesplit(split);
		free(split);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			ft_create_node(&head_a, av[i]);
			i++;
		}
	}
	return (head_a);
}

int	ft_check_doubles(t_stack **stack_a)
{
	t_stack	*i;
	t_stack	*j;

	i = *stack_a;
	j = i->next;
	while (i && j)
	{
		while (j)
		{
			if (i->content == j->content)
				return (1);
			j = j->next;
		}
		i = i->next;
		j = i->next;
	}
	return (0);
}

int	ft_check_sorted(t_stack **stack)
{
	t_stack	*cmp;
	t_stack	*i;

	cmp = *stack;
	i = cmp->next;
	while (cmp && i)
	{
		while (i)
		{
			if (cmp->content > i->content)
				return (0);
			i = i->next;
		}
		cmp = cmp->next;
		i = cmp->next;
	}
	return (1);
}
