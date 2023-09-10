#include "llist.h"





t_list *list_get(t_list *list, size_t pos)
{
    t_list *tmp;
    size_t i;

    if (!list)
        return (NULL);
    if (pos == 0)
        return (list);
    tmp = list;
    i = 0;
    while (tmp && i < pos)
    {
        tmp = tmp->next;
        i++;
    }
    return (tmp);
}



t_list *list_get_back(t_list *list)
{
    t_list *tmp;

    if (!list)
        return (NULL);
    tmp = list;
    while (tmp->next)
        tmp = tmp->next;
    return (tmp);
}


void list_iter(t_list *list, void (*f)(void *))
{
    t_list *tmp;

    if (!list || !f)
        return ;
    tmp = list;
    while (tmp)
    {
        f(tmp->data);
        tmp = tmp->next;
    }
}

void list_iter_rev(t_list *list, void (*f)(void *))
{
    t_list *tmp;

    if (!list || !f)
        return ;
    tmp = list_get_back(list);
    while (tmp)
    {
        f(tmp->data);
        tmp = tmp->prev;
    }
}

void list_clear(t_list **list, void (*free_data)(void *))
{
    t_list *tmp;

    if (!list || !*list)
        return ;
    tmp = *list;
    while (tmp->next)
    {
        tmp = tmp->next;
        if (free_data)
            free_data(tmp->prev->data);
        free(tmp->prev);
    }
    if (free_data)
        free_data(tmp->data);
    free(tmp);
    *list = NULL;
}


void list_copy(t_list **dst, t_list *src, void *(*copy_data)(void *))
{
    t_list *tmp;

    if (!dst || !src)
        return ;
    tmp = src;
    while (tmp)
    {
        list_add_back(dst, list_new(copy_data(tmp->data)));
        tmp = tmp->next;
    }
}

void list_copy_rev(t_list **dst, t_list *src, void *(*copy_data)(void *))
{
    t_list *tmp;

    if (!dst || !src)
        return ;
    tmp = src;
    while (tmp)
    {
        list_add_front(dst, list_new(copy_data(tmp->data)));
        tmp = tmp->next;
    }
}


void list_sort(t_list **list, int (*cmp)(void *, void *))
{
    t_list *tmp;
    t_list *tmp2;
    void *data;

    if (!list || !*list || !cmp)
        return ;
    tmp = *list;
    while (tmp)
    {
        tmp2 = tmp->next;
        while (tmp2)
        {
            if (cmp(tmp->data, tmp2->data) > 0)
            {
                data = tmp->data;
                tmp->data = tmp2->data;
                tmp2->data = data;
            }
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
}




t_list *list_find(t_list *list, void *data, int (*cmp)(void *, void *))
{
    t_list *tmp;

    if (!list || !cmp)
        return (NULL);
    tmp = list;
    while (tmp)
    {
        if (cmp(tmp->data, data) == 0)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}