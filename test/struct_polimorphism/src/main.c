#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fcd_structs.h"
#include "print_fcd_st.h"


static fcd_root_block* root_block;

static fcd_block_block *
    new_block_block(const char* title)
{
    fcd_block_block* block = (fcd_block_block*)malloc(sizeof(fcd_block_block));
    block->type = BLOCK_T_BLOCK;
    block->title = strdup(title);
    return block;
}

static fcd_text_block *
    new_text_block(const char* data)
{
    fcd_text_block* block = (fcd_text_block*)malloc(sizeof(fcd_text_block));
    block->type = BLOCK_T_TEXT;
    block->data = strdup(data);
    return block;
}

static fcd_image_block *
    new_image_block(const char* alt, const char* path)
{
    fcd_image_block* block = (fcd_image_block*)malloc(sizeof(fcd_image_block));
    block->type = BLOCK_T_IMAGE;
    block->path = strdup(path);
    block->alt = strdup(alt);
    return block;
}

static fcd_code_block *
    new_code_block(const char* data)
{
    fcd_code_block* block = (fcd_code_block*)malloc(sizeof(fcd_code_block));
    block->type = BLOCK_T_CODE;
    block->data = strdup(data);
    return block;
}

int main(void)
{
    /* alloc root */
    root_block = malloc(sizeof(fcd_root_block*));

    /* alloc 2 ptrs */
    root_block->blocks = (fcd_block_block**)malloc( sizeof(fcd_block_block*) * 2 );
    root_block->blocks_count = 2;

    /* allocs blocks in root */
    root_block->blocks[0] = new_block_block("Chapter 0");
    root_block->blocks[1] = new_block_block("Chapter 1");
    //root_block->blocks[2] = new_block_block("Chapter 2");
    //root_block->blocks[3] = new_block_block("Chapter 3");
    
    
    /* work with 0 chapter */
    root_block->blocks[0]->child_blocks = malloc(sizeof(void*)*3);
    root_block->blocks[0]->child_blocks[0] = new_text_block("This is description");
    root_block->blocks[0]->child_blocks[1] = new_text_block("This is big text");
    root_block->blocks[0]->child_blocks[2] = new_code_block("#python3 code\nprint('Hello world')\n");
    root_block->blocks[0]->child_blocks_count = 3;


    /* work with 1 chapter */
    root_block->blocks[1]->child_blocks = malloc(sizeof(void*)*3);
    root_block->blocks[1]->child_blocks[0] = new_text_block("This is description");
    root_block->blocks[1]->child_blocks[1] = new_block_block("Subchapter 0 in chpr 1");
    root_block->blocks[1]->child_blocks[2] = new_text_block("text...");
    root_block->blocks[1]->child_blocks_count = 3;

    /* sub chptr */
    ((fcd_block_block*)root_block->blocks[1]->child_blocks[1])->child_blocks = malloc(sizeof(void*)*2);
    ((fcd_block_block*)root_block->blocks[1]->child_blocks[1])->child_blocks[0] = new_text_block("sub 1");
    ((fcd_block_block*)root_block->blocks[1]->child_blocks[1])->child_blocks[1] = new_text_block("sub 2");
    ((fcd_block_block*)root_block->blocks[1]->child_blocks[1])->child_blocks_count = 2;
    //root_block->blocks[1]->child_blocks[1]->child_blocks[0] = new_text_block("sub 1");
    //root_block->blocks[1]->child_blocks[1]->child_blocks[0] = new_text_block("sub 2");
    
    
    // printf("%d\n", ((fcd_base_block*)root_block->blocks[0]->child_blocks[0])->type);

    print_fcd_root_block_tree(root_block);

}

