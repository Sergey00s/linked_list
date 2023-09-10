#include "llist.h"


void list_pop(t_list **list, size_t pos, void (*free_data)(void *))
{
    t_list *tmp;
    size_t i;

    if (!list || !*list)
        return ;
    if (pos == 0)
    {
        list_pop_front(list, free_data);
        return ;
    }
    tmp = *list;
    i = 0;
    while (tmp && i < pos)
    {
        tmp = tmp->next;
        i++;
    }
    if (!tmp)
        return ;
    if (tmp->prev)
        tmp->prev->next = tmp->next;
    if (tmp->next)
        tmp->next->prev = tmp->prev;
    if (free_data)
        free_data(tmp->data);
    free(tmp);
}

void list_pop_back(t_list **list, void (*free_data)(void *))
{
    t_list *tmp;

    if (!list || !*list)
        return ;
    tmp = *list;
    while (tmp->next)
        tmp = tmp->next;
    if (tmp->prev)
        tmp->prev->next = NULL;
    if (free_data)
        free_data(tmp->data);
    free(tmp);
}


void list_pop_front(t_list **list, void (*free_data)(void *))
{
    t_list *tmp;

    if (!list || !*list)
        return ;
    tmp = *list;
    *list = (*list)->next;
    if (*list)
        (*list)->prev = NULL;
    if (free_data)
        free_data(tmp->data);
    free(tmp);
}

void list_remove_by_data_addr(t_list **list, void *data, void (*free_data)(void *))
{
    t_list *tmp;

    if (!list || !*list || !data)
        return ;
    tmp = *list;
    while (tmp)
    {
        if (tmp->data == data)
        {
            if (tmp->prev)
                tmp->prev->next = tmp->next;
            if (tmp->next)
                tmp->next->prev = tmp->prev;
            if (tmp == *list)
                *list = tmp->next;
            if (free_data)
                free_data(tmp->data);
            free(tmp);
            return ;
        }
        tmp = tmp->next;
    }
}


void list_remove_by_data_if(t_list **list, void *data, int (*cmp)(void *, void *), void (*free_data)(void *))
{
    t_list *tmp;

    if (!list || !*list || !cmp)
        return ;
    tmp = *list;
    while (tmp)
    {
        if (cmp(tmp->data, data) == 0)
        {
            if (tmp->prev)
                tmp->prev->next = tmp->next;
            if (tmp->next)
                tmp->next->prev = tmp->prev;
            if (tmp == *list)
                *list = tmp->next;
            if (free_data)
                free_data(tmp->data);
            free(tmp);
            return ;
        }
        tmp = tmp->next;
    }
}


void list_remove_by_addr(t_list **list, t_list *addr, void (*free_data)(void *))
{
    t_list *tmp;

    if (!list || !*list || !addr)
        return ;
    tmp = *list;
    while (tmp)
    {
        if (tmp == addr)
        {
            if (tmp->prev)
                tmp->prev->next = tmp->next;
            if (tmp->next)
                tmp->next->prev = tmp->prev;
            if (tmp == *list)
                *list = tmp->next;
            if (free_data)
                free_data(tmp->data);
            free(tmp);
            return ;
        }
        tmp = tmp->next;
    }
}