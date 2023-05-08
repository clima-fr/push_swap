#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
  int content;
  struct stack *next;
  //int distance_top;
  //int index;
} t_stack;

void printf_list(t_stack **head)
{
    t_stack *cur = *head;
    while(cur != 0)
    {
        printf("%d\n", cur->content);
        cur = cur->next;
    }
    if(cur == 0)
        printf("( LIST )\n");
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	if (new)
	{
		new->content = content;
		new->next = NULL;
	}
	return (new);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (lst && *lst && new)
	{
		current = *lst;
		while (current->next != 0)
		{
			current = current->next;
		}
		current->next = new;
	}
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
}

void	pb(t_stack **b, t_stack **a)
{
	push(&(*b),&(*a));
}

int main(int ac, char** av)
{
    if(ac < 2)
    {
        printf("Mensagem de Erro\n");
        //________FUNCAO DE ERROR________//
        return(0);
    }
    else if(ac == 2)
    {
        printf("Ft_split rodara aqui\n");
        //________FUNCAO SPLIT________//
        return(0);
    }
    else if(ac > 2)
    {
        //________FUNCAO CRIACAO DA STACK A________
        t_stack *head_a;
        head_a = ft_lstnew(atoi(av[1]));
        
        int i;
        i = 2;
        int numb;
        while(i < ac)
        {
            numb = atoi(av[i]);
            ft_lstadd_back(&head_a, ft_lstnew(numb));
            i++;
        }
        //________FIM STACK A__________________________

        //----------------------------->FUNCAO VERIFICAR REPETIDOS
        //----------------------------->FUNCAO VERIFICAR ORDEM

        //________FUNCAO CRIACAO DA STACK B___________
        t_stack *head_b;
        head_b = 0;
        //________FIM STACK B_________________________

        printf("Lista Original A:\n");
        printf_list(&head_a);
        printf("Lista Original B:\n");
        printf_list(&head_b);

        pb(&head_b, &head_a);
        pb(&head_b, &head_a);

        printf("Lista Atualizada A:\n");
        printf_list(&head_a);
        printf("Lista Atualizada B:\n");
        printf_list(&head_b);
    }
}