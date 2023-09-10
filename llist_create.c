#include "llist.h"


t_list *list_new(void *data)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

void list_add_back(t_list **list, t_list *new)
{
    t_list *tmp;

    if (!list || !new)
        return ;
    if (!*list)
    {
        *list = new;
        return ;
    }
    tmp = *list;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    new->prev = tmp;
}

void list_add_front(t_list **list, t_list *new)
{
    if (!list || !new)
        return ;
    if (!*list)
    {
        *list = new;
        return ;
    }
    new->next = *list;
    (*list)->prev = new;
    *list = new;
}


void list_put(t_list **list, t_list *new, size_t pos)
{
    t_list *tmp;
    size_t  i;

    if (!list || !new)
        return ;
    if (!*list)
    {
        *list = new;
        return ;
    }
    tmp = *list;
    i = 0;
    while (tmp->next && i < pos)
    {
        tmp = tmp->next;
        i++;
    }
    if (i == pos)
    {
        new->next = tmp;
        new->prev = tmp->prev;
        tmp->prev->next = new;
        tmp->prev = new;
    }
    else
        list_add_back(list, new);
}




