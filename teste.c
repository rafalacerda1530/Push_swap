#include "./push_swap.h"

t_stack *new_node (void)
{
    t_stack *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    new_node->next = NULL;
    new_node->num = 0;

    return (new_node);
}

void testando(t_stack **teste)
{
    t_stack *tmp;
    t_stack *aux;
    int i;

    i = 1;
    aux = *teste;
    while (i < 10)
    {
        aux->num = i;
        tmp =  new_node();
        aux->next = tmp;
        aux = aux->next;
        i++;
    }
}

int main(void)
{
    t_swap *teste;
    int i;

    i  = 0;
    teste->stack_a = new_node();
    testando(&teste->stack_a);
    while (teste->stack_a)
    {
        printf("teste = %d\n", teste->stack_a->num);
        teste->stack_a = teste->stack_a->next;
        i++;
    }
    return(1);
}
