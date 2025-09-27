#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

/*
   Print List
*/
static void print_list (const DList *list) {
    DListNode *node;
    int *data, i;

    fprintf(stdout, "DList size is %d\n", dlist_size(list));

    i = 0;
    node = dlist_head(list);

    while (node != NULL) {
        data = dlist_data(node);
        fprintf(stdout, "dlist.node[%03d]=%03d, %14p <- %p -> %p \n",
                i, *data, node->prev, node, node->next);

        i++;
        if (dlist_is_tail(node))
            break;
        else
            node = dlist_next(node);
    }
    return;
}

int main (int argc, char **argv) {
    DList list;
    DListNode *node;
    int *data, i;

    if (argc < 2) {
        fprintf(stderr, "Uso: %s num1 num2 num3 ...\n", argv[0]);
        return 1;
    }

    dlist_init(&list, free);

    for (i = 1; i < argc; i++) {
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;

        *data = atoi(argv[i]);

        if (dlist_size(&list) == 0) {
            if (dlist_ins_next(&list, NULL, data) != 0)
                return 1;
        } else {
            if (dlist_ins_next(&list, dlist_tail(&list), data) != 0)
                return 1;
        }
    }

    print_list(&list);

    node = dlist_head(&list);

    for (i = 0; i < 2 && node != NULL; ++i)
        node = dlist_next(node);

    if (node != NULL) {
        data = dlist_data(node);
        fprintf(stdout, "\nRemoving a node after the one containing %03d\n", *data);

        if (dlist_remove(&list, node, (void**)&data) == 0)
            free(data);
    }

    print_list(&list);

    fprintf(stdout, "\nInserting 187 at the tail of the list\n");
    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return 1;
    *data = 187;
    if (dlist_ins_next(&list, dlist_tail(&list), data) != 0)
        return 1;
    print_list(&list);

    fprintf(stdout, "\nRemoving a node at the tail of the list\n");
    if (dlist_remove(&list, dlist_tail(&list), (void**)&data) == 0)
        free(data);
    print_list(&list);

    fprintf(stdout, "\nInsert 975 before the tail of the list\n");
    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return 1;
    *data = 975;
    if (dlist_ins_prev(&list, dlist_tail(&list), data) != 0)
        return 1;
    print_list(&list);
    
    fprintf(stdout, "\nDestroying the list\n");
    dlist_destroy(&list);

    return 0;
}
