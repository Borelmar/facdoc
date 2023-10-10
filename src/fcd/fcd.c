/* 
 * It file store a functions for work with structs from a ./fcd.h.
 * Copyright (C) 2023 Free Software Foundation, Inc.
 *
 * This file is part of facdoc.
 *
 * Facdoc is free software: you can redistribute it and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * Foobar is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Foobar. If not, see <https://www.gnu.org/licenses/>. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fcd.h"

static fcd_root_block* root_block;

static fcd_section_block *
    new_section_block(const char* title)
{
    fcd_section_block* block = (fcd_section_block*)malloc(sizeof(fcd_section_block));
    block->type = BLOCK_T_SECTION;
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

static fcd_section_block *
    maken_nodes(fcd_section_block* block, unsigned int n, unsigned int depth)
{
    if(n == 0)
    {
        return NULL;
    }

    //for(unsigned int i = 0; i < n; )

}


int __main(void)
{
    /* alloc root */
    root_block = malloc(sizeof(fcd_root_block*));

    /* alloc 2 ptrs */
    root_block->sections = (fcd_section_block**)malloc( sizeof(fcd_section_block*) * 2 );
    root_block->sections_count = 2;

    /* allocs blocks in root */
    root_block->sections[0] = new_section_block("Chapter 0");
    root_block->sections[1] = new_section_block("Chapter 1");
    
    /* work with 0 chapter */
    root_block->sections[0]->blocks = malloc(sizeof(void*)*3);
    root_block->sections[0]->blocks[0] = new_text_block("This is description");
    root_block->sections[0]->blocks[1] = new_text_block("This is big text");
    root_block->sections[0]->blocks[2] = new_code_block("#python3 code\nprint('Hello world')\n");
    root_block->sections[0]->blocks_count = 3;


    /* work with 1 chapter */
    root_block->sections[1]->blocks = malloc(sizeof(void*)*3);
    root_block->sections[1]->blocks[0] = new_text_block("This is description");
    root_block->sections[1]->blocks[1] = new_section_block("Subchapter 0 in chpr 1");
    root_block->sections[1]->blocks[2] = new_text_block("text...");
    root_block->sections[1]->blocks_count = 3;

    /* sub chptr */
    ((fcd_section_block*)root_block->sections[1]->blocks[1])->blocks = malloc(sizeof(void*)*2);
    ((fcd_section_block*)root_block->sections[1]->blocks[1])->blocks[0] = new_text_block("sub 1");
    ((fcd_section_block*)root_block->sections[1]->blocks[1])->blocks[1] = new_text_block("sub 2");
    ((fcd_section_block*)root_block->sections[1]->blocks[1])->blocks_count = 2;
    //root_block->sections[1]->blocks[1]->blocks[0] = new_text_block("sub 1");
    //root_block->sections[1]->blocks[1]->blocks[0] = new_text_block("sub 2");
    
    
    // printf("%d\n", ((fcd_base_block*)root_block->sections[0]->blocks[0])->type);

    print_fcd_root_block_tree(root_block);

}
