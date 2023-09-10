#include "llist.h"

int list_default_cmp(void *a, void *b)
{
    return (a - b);
}

int list_default_free(void *data)
{
    free(data);
    return (1);
}

int list_default_sum(void *data)
{
    return (*(int *)data);
}



size_t list_size(t_list *list)
{
    size_t size;
    t_list *tmp;

    if (!list)
        return (0);
    tmp = list;
    size = 0;
    while (tmp)
    {
        tmp = tmp->next;
        size++;
    }
    return (size);
}

size_t list_sum(t_list *list, int (*f)(void *))
{
    size_t sum;
    t_list *tmp;

    if (!list || !f)
        return (0);
    tmp = list;
    sum = 0;
    while (tmp)
    {
        sum += f(tmp->data);
        tmp = tmp->next;
    }
    return (sum);
}