#include <stdio.h>
#include <stdlib.h>

struct toc_item
{
    unsigned int ordinal_num;
    unsigned int items_count;
    struct toc_item** items;
};

typedef struct fcd_toc_entity
{
    char* title;
    unsigned int items_count;
    struct toc_item** toc_root;
} toc;

int main(void)
{
    toc *toc_p = malloc(sizeof(toc));
    toc_p->title = malloc(30);
    gets(toc_p->title);

    toc_p->toc_root = malloc(sizeof(struct toc_item**));
    toc_p->toc_root[0] = malloc(sizeof(struct toc_item*));
    toc_p->toc_root[1] = malloc(sizeof(struct toc_item*));
    toc_p->toc_root[1]->ordinal_num = 1;
    toc_p->toc_root[1]->items = malloc(sizeof(struct toc_item**));
    toc_p->toc_root[1]->items[0] = malloc(sizeof(struct toc_item*));
    toc_p->toc_root[1]->items[0]->ordinal_num = 1337;
    toc_p->toc_root[1]->items[0]->items = malloc(sizeof(struct toc_item**));
    toc_p->toc_root[1]->items[0]->items[0] = malloc(sizeof(struct toc_item*));
    toc_p->toc_root[1]->items[0]->items[0]->ordinal_num = 31337;

    /* free */
    free(toc_p->toc_root[1]->items);
    free(toc_p->toc_root[1]);
    free(toc_p->toc_root[0]);
    free(toc_p->toc_root);

    return 0;
}
