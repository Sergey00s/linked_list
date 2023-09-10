#ifndef LLIST_H
# define LLIST_H

# include <stdlib.h>


typedef struct s_node
{
    void			*data;
    struct s_node	*prev;
    struct s_node	*next;
}	t_list;


t_list *list_new(void *data);
void list_add_back(t_list **list, t_list *new);
void list_add_front(t_list **list, t_list *new);
void list_put(t_list **list, t_list *new, size_t pos);
void list_pop(t_list **list, size_t pos, void (*free_data)(void *));
void list_pop_back(t_list **list, void (*free_data)(void *));
void list_pop_front(t_list **list, void (*free_data)(void *));
void list_remove_by_data_addr(t_list **list, void *data, void (*free_data)(void *));
void list_remove_by_data_if(t_list **list, void *data,int (*cmp)(void *, void *), void (*free_data)(void *));
void list_remove_by_addr(t_list **list, t_list *addr, void (*free_data)(void *));

//list operations

t_list  *list_get(t_list *list, size_t pos);
t_list  *list_get_back(t_list *list);
void    list_iter(t_list *list, void (*f)(void *));
void    list_iter_rev(t_list *list, void (*f)(void *));
void    list_clear(t_list **list, void (*free_data)(void *));
void    list_copy(t_list **dest, t_list *src, void *(*copy_data)(void *));
void    list_copy_rev(t_list **dest, t_list *src, void *(*copy_data)(void *));
void    list_sort(t_list **list, int (*cmp)(void *, void *));
t_list  *list_find(t_list *list, void *data, int (*cmp)(void *, void *));



//lsit sizer

int    list_default_cmp(void *a, void *b);
int    list_default_free(void *data);
int    list_default_sum(void *data);
size_t list_size(t_list *list);
size_t list_sum(t_list *list, int (*f)(void *));


# define DEF_CMP list_default_cmp
# define DEF_FREE list_default_free
# define DEF_SUM list_default_sum

#endif