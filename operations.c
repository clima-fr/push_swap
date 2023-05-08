/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clima-fr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:47:52 by clima-fr          #+#    #+#             */
/*   Updated: 2023/05/04 10:48:03 by clima-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
typedef struct stack
{
  int content;
  struct stack *next;
  //int distance_top;
  //int index;
} t_stack;

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
		}
	}
	else
	{
		return (NULL);
	}
	return (lst);
}

void    swap(t_stack **stack)
{
	t_stack	*tmp;
	if (!*stack || !((*stack)->next))
		return ;
	tmp = *stack; 
	*stack = (*stack)->next; 
	tmp->next = (*stack)->next; 
	(*stack)->next = tmp; 
	/*if (j == 0)
		write(1, "sa\n", 3);*/
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = ft_lstlast(*stack);
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
	/*if (j == 0)
		write(1, "ra\n", 3);*/
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	if (!*stack || !(*stack)->next)
		return ;
	i = 0;
	tmp = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	/*if (j == 0)
		write(1, "rra\n", 4);*/
}

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *dest;
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = tmp;
	/*if (j == 0)
		write(1, "pa\n", 3);*/
}

void	sa(t_stack **a)
{
	swap(&(*a));
}

void	sb(t_stack **b)
{
	swap(&(*b));
}

void	ss(t_stack **a, t_stack **b)
{
	swap(&(*a));
	swap(&(*b));
}

void	ra(t_stack **a)
{
	rotate(&(*a));
}

void	rb(t_stack **b)
{
	rotate(&(*b));
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(&(*a));
	rotate(&(*b));
}

void	rra(t_stack **a)
{
	reverse_rotate(&(*a));
}

void	rrb(t_stack **b)
{
	reverse_rotate(&(*b));
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(&(*a));
	reverse_rotate(&(*b));
}

void	pa(t_stack **a, t_stack **b)
{
	push(&(*a),&(*b));
}

void	pb(t_stack **b, t_stack **a)
{
	push(&(*b),&(*a));
}



#include <stdlib.h>
int        main()
{
    //Criação dos nós stack A
    t_stack *ano1;
    int an1 = 10;
    ano1 = malloc(sizeof(t_stack));
    ano1->next = NULL;
    ano1->content = an1;
    
    t_stack *ano2;
    int an2 = 20;
    ano2 = malloc(sizeof(t_stack));
    ano2->next = NULL;
    ano2->content = an2;
    
    t_stack *ano3;
    int an3 = 30;
    ano3 = malloc(sizeof(t_stack));
    ano3->next = NULL;
    ano3->content = an3;
    
    t_stack *ano4;
    int an4 = 40;
    ano4 = malloc(sizeof(t_stack));
    ano4->next = NULL;
    ano4->content = an4;
    
    //Criação dos nós stack B
    t_stack *bno1;
    int bn1 = 23;
    bno1 = malloc(sizeof(t_stack));
    bno1->next = NULL;
    bno1->content = bn1;
    
    t_stack *bno2;
    int bn2 = 13;
    bno2 = malloc(sizeof(t_stack));
    bno2->next = NULL;
    bno2->content = bn2;
    
    t_stack *bno3;
    int bn3 = 10;
    bno3 = malloc(sizeof(t_stack));
    bno3->next = NULL;
    bno3->content = bn3;
    
    t_stack *bno4;
    int bn4 = 4;
    bno4 = malloc(sizeof(t_stack));
    bno4->next = NULL;
    bno4->content = bn4;
    
    // Criação da lista encadeada stack A
    t_stack *heada = ano1;
    ano1->next = ano2;
    ano2->next = ano3;
    ano3->next = ano4;
    
    // Criação da lista encadeada stack B
    t_stack *headb = bno1;
    bno1->next = bno2;
    bno2->next = bno3;
    bno3->next = bno4;
    
    // Impressão do conteúdo da lista original
    printf("\nLista Original:\n");
    t_stack *i = heada;
    t_stack *j = headb; 
    while(i != 0 || j != 0)
    {
      printf("%d		%d\n", i->content, j->content);
      if (i != 0)
      	i = i->next;
      if (j != 0)
      	j = j->next;
      if(i == 0 && j == 0)
      {
      	printf("( A )		( B )\n");
      }
    }
	//swap(&heada);
	//rotate(&heada);
	//reverse_rotate(&heada);
	//push(&heada, &headb);
	//sa(&heada);
	//ra(&heada);
	//rra(&heada);
	pb(&headb, &heada);
	//ss(&heada, &headb);
    
    // Adição de um novo nó no início da lista
    printf("\nLista Atualizada:\n");
    i = heada;
    j = headb; 
    int cont = 0;
    while(cont < 5)
    {
      printf("%d		%d\n", i->content, j->content);
      if (i != 0)
      	i = i->next;
      if (j != 0)
      	j = j->next;
      /*if(i == 0 && j == 0)
      {
      	printf("( A )		( B )\n");
      }*/
      cont++;
    }
}
