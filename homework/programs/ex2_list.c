#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
   Print List
*/
static void print_list (const List *list) {
    ListNode *node;
    char *data;
    int i;

    fprintf(stdout, "List size is %d\n", list_size(list));

    i = 0;
    node = list_head(list);

    while (1) {
        data = list_data(node);
        fprintf(stdout, "list.node[%03d] = '%c' (ASCII %03d), %p -> %p \n",
                i, *data, *data, node, node->next);

        i++;

        if (list_is_tail(node))
            break;
        else
            node = list_next(node);
    }

   return;
}

int main (int argc, char **argv) {
    List list;
    ListNode *node;
    char *data;
    int i;

    list_init(&list, free);

    for (i = 0; i < 26; i++) {
        if ((data = (char *)malloc(sizeof(char))) == NULL)
            return 1;
        *data = 'A' + i;
        if (list_ins_next(&list, NULL, data) != 0)
            return 1;
    }

    if ((data = (char *)malloc(sizeof(char))) == NULL)
        return 1;
    *data = '_';
    if (list_ins_next(&list, NULL, data) != 0)
        return 1;

    print_list(&list);

    node = list_head(&list);
    for (i = 0; i < 5; ++i)
        node = list_next(node);

    data = list_data(node);
    fprintf(stdout, "\nRemoving a node after the one containing '%c'\n", *data);

    if (list_rem_next(&list, node, (void**)&data) == 0)
        free(data);

    print_list(&list);

    fprintf(stdout, "\nInserting '!' at the tail of the list\n");
    if ((data = (char *)malloc(sizeof(char))) == NULL)
        return 1;
    *data = '!';
    if (list_ins_next(&list, list_tail(&list), data) != 0)
        return 1;

    print_list(&list);

    fprintf(stdout, "\nRemoving a node after the first node\n");
    if (list_rem_next(&list, list_head(&list), (void**)&data) == 0)
        free(data);
    print_list(&list);

    fprintf(stdout, "\nInsert '#' at the head of the list\n");
    if ((data = (char *)malloc(sizeof(char))) == NULL)
        return 1;
    *data = '#';
    if (list_ins_next(&list, NULL, data) != 0)
        return 1;
    print_list(&list);

    fprintf(stdout, "\nDestroying the list\n");
    list_destroy(&list);

    return 0;
}
