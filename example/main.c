#include <llist.h>

#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    t_list *list = NULL;

    list_add_back(&list, list_new("Hello0"));
    list_add_back(&list, list_new("World"));
    list_add_back(&list, list_new("!!!"));
    list_add_front(&list, list_new("Hello1"));

    list_iter(list, &puts);
    puts("-----");
    list_iter_rev(list, &puts);
    puts("-----");
    list_pop(&list, 0, NULL);
    list_iter(list, &puts);
    puts("-----");
    list_pop_back(&list, NULL);
    list_iter(list, &puts);


    printf("list size: %zu\n", list_size(list));

   // list_clear(&list, NULL);

    printf("list size: %zu\n", list_size(list));

    list_remove_by_data_if(&list, "Hello0", &strcmp, NULL);
    puts("-----");
    list_iter(list, &puts);
    puts("-----");



    return 0;
}
