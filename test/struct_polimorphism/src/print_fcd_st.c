#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "fcd_structs.h"

static void
    print_fcd_text_block(fcd_text_block * block, unsigned int depth)
{
    printf("** begin text block **\n");
    char *pattrn = "%stype: '%d'\n\
%smodifers: '%p'\n\
%sdata: '%s'\n";

    char* ofs = chrmult(' ', depth*4);

    printf(pattrn, ofs, block->type, ofs, block->modifers, ofs, block->data);
    printf("** end text block **\n");
}

static void
    print_fcd_image_block(fcd_image_block * block, unsigned int depth)
{
    char* ofs = chrmult(' ', depth*4);
    printf("%s** begin image block **\n", ofs);

    char *pattrn = "%stype: '%d'\n\
%salt: '%s'\n\
%spath: '%s'\n";

    printf(pattrn, ofs, block->type, ofs, block->alt, ofs, block->path);
    printf("%s** end image block **\n", ofs);
}

static void
    print_fcd_code_block(fcd_code_block * block, unsigned int depth)
{
    char* ofs = chrmult(' ', depth*4);
    printf("%s** begin code block **\n", ofs);

    char *pattrn = "\
%stype: '%d'\n\
%smarks ptr: '%p'\n\
%sdata: '%s'\n";
    printf(pattrn, ofs, block->type, ofs, block->marks, ofs, block->data);

    printf("%s** end code block **\n", ofs);
}


static void
    print_fcd_section_block(fcd_section_block * block, unsigned int depth)
{
    char* ofs = chrmult(' ', depth*4);
    printf("%s** begin bblock **\n", ofs);

    char *bl_info_pattrn = "%stype: '%d'\n\
%schild blocks count '%d'\n\
%stitle: '%s'\n";

    printf(bl_info_pattrn, ofs, block->type, ofs, block->child_blocks_count, ofs, block->title);

    /* print child blocks */
    for(unsigned int i = 0; i < block->child_blocks_count; i++)
    {
        switch( ( (fcd_base_block*)block->child_blocks[i] )->type )
        {
            case(BLOCK_T_SECTION):
                print_fcd_section_block(block->child_blocks[i], depth+1);
                break;
            case(BLOCK_T_TEXT):
                print_fcd_text_block(block->child_blocks[i], depth+1);
                break;
            case(BLOCK_T_IMAGE):
                print_fcd_image_block(block->child_blocks[i], depth+1);
                break;
            case(BLOCK_T_CODE):
                print_fcd_code_block(block->child_blocks[i], depth+1);
                break;
        }
    }
    printf("%s** end bblock **\n", ofs);
}

void
    print_fcd_root_block_tree(fcd_root_block* root_block)
{
    unsigned int depth = 0;
    printf("*** BEGIN ROOT ***\n");
    printf("blocks count: '%d'\n", root_block->blocks_count);
    for(unsigned int i = 0; i < root_block->blocks_count; i++)
    {
        printf("** block '%d' **", i);
        print_fcd_section_block(root_block->blocks[i], depth);
        printf("** end block '%d' **", i);
    }
    printf("*** END ROOT ***\n");
}
