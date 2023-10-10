/* 
 * html translator of fcd format.
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

#define _GNU_SOURCE
#include "config.h"

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <error.h>


/*
#ifdef HAVE_ALLOCA_H
#   include <alloca.h>
#else
#   error "Not have alloca.h"
#endif
*/

#include "fcd.h"
#include "html.h"
#include "css.h"
#include "util.h"

static char *_translate_toc()
{
    char *ret;
    return ret;
}

static char *_translate_tmodifer(char *data, fcd_text_modifer *modifer)
{
    char *ret;
    switch(modifer->type)
    {
        case (TMOD_T_BOLD):
            asprintf(&ret,
                    HTML_TMOD_BOLD_FMT, data);
            return ret;
        case (TMOD_T_ITALIC):
            asprintf(&ret,
                    HTML_TMOD_ITALIC_FMT, data);
            return ret;
        case (TMOD_T_UNDERLINE):
            asprintf(&ret,
                    HTML_TMOD_ITALIC_FMT, data);
            return ret;
        case (TMOD_T_MARK):
            asprintf(&ret,
                    HTML_TMOD_MARK_FMT, data);
            return ret;
        case (TMOD_T_SUPERSCRIPT):
            asprintf(&ret,
                    HTML_TMOD_SUPERSCRIPT_FMT,
                    data);
            return ret;
        case (TMOD_T_SUBSCRIPT):
            asprintf(&ret,
                    HTML_TMOD_SUBSCRIPT_FMT,
                    data);
            return ret;
        case (TMOD_T_LINK):
            asprintf(&ret,
                    HTML_TMOD_LINK_FMT,
                    modifer->extra_data, data);
            return ret;
        case (TMOD_T_DEL):
            asprintf(&ret,
                    HTML_TMOD_DEL_FMT,
                    data);
            return ret;
    }
    return NULL;
}

static char *_translate_text_block(fcd_text_block *text_block)
{
    char *ret;
    register unsigned int curr_data_offset = 0;
    char *data_in_text_block = NULL;

    for (unsigned int i = 0; i < text_block->modifers_count; i++)
    {
        // text_block->modifers[i]->offset_start;
        /* wrapping text via html text modifers (end - start = size) */

        char p[text_block->modifers[i]->offset_end
                - text_block->modifers[i]->offset_start];

        /* wrapping... */
        char *trl_p = _translate_tmodifer(p, text_block->modifers[i]);


        /* calculate a needed copy a previos, non-modified text */
        if (text_block->modifers[i]->offset_start > curr_data_offset)
        {
            if (data_in_text_block != NULL)
            {
                register char *old_p = data_in_text_block;
                data_in_text_block = astrncat(data_in_text_block,
                        text_block->data+curr_data_offset,
                        text_block->modifers[i]->offset_start-curr_data_offset);
                free(old_p);
            }
            else
            {
                data_in_text_block = strndup(text_block->data, text_block->modifers[i]->offset_start);
            }
        }

        if (data_in_text_block == NULL)
        {
            data_in_text_block = strdup(trl_p);
        }
        else
        {
            register char *old_p = data_in_text_block;
            data_in_text_block = astrcat(data_in_text_block, trl_p);
            free(old_p);
        }
    }

    asprintf(&ret,
            HTML_TEXT_FORMAT,
            data_in_text_block);

    free(data_in_text_block);

    return ret;
}

static char *_translate_table_block(fcd_table_block *table_block)
{
    char *ret;
    return ret;
}

static char *_translate_code_block(fcd_code_block *code_block)
{
    char *ret;
    return ret;
}

static char *_translate_image_block(fcd_image_block *image_block)
{
    char *ret;
    /* checking for base64 mode and path mode */
    if (image_block->data)
    {
        asprintf(&ret, HTML_IMAGE_BASE64_STORE_FORMAT, image_block->data, image_block->alt);
    }
    else
    {
        asprintf(&ret, HTML_IMAGE_PATH_STORE_FORMAT, image_block->path, image_block->alt);
    }
    return ret;
}

static char *_translate_note_block(fcd_note_block *note_block)
{
    char *ret;
    asprintf(&ret, HTML_NOTE_FMT, note_block->data);
    return ret;
}

static char *_translate_link_block(fcd_link_block *link_block)
{
    char *ret;
    asprintf(&ret, HTML_LINK_FMT, link_block->link, link_block->text);
    return ret;
}

static char *_translate_section_block
    (fcd_section_block *section_block, fcd_toc_node *toc_node)
{
    char *ret;
    unsigned int title_size = strlen(section_block->title);
    
    char **translated_blocks =
        (char**)malloc(sizeof(char*) * section_block->blocks_count);

    /*
     * its compile each fcd block in section_block->blocks[]
     */
    for (unsigned int i; i < section_block->blocks_count; i++)
    {
        switch( ((fcd_base_block*)section_block->blocks[i])->type )
        {
            case(BLOCK_T_SECTION):
                translated_blocks[i] = 
                    _translate_section_block(section_block->blocks[i], toc_node->nodes[i]);
                break;

            case(BLOCK_T_TEXT):
                translated_blocks[i] = 
                    _translate_text_block(section_block->blocks[i]);
                break;

            case(BLOCK_T_IMAGE):
                translated_blocks[i] = 
                    _translate_image_block(section_block->blocks[i]);
                break;

            case(BLOCK_T_CODE):
                translated_blocks[i] = 
                    _translate_code_block(section_block->blocks[i]);
                break;

            case(BLOCK_T_NOTE):
                translated_blocks[i] = 
                    _translate_note_block(section_block->blocks[i]);
                break;

            case(BLOCK_T_LINK):
                translated_blocks[i] = 
                    _translate_link_block(section_block->blocks[i]);
                break;

            case(BLOCK_T_TABLE):
                translated_blocks[i] = 
                    _translate_table_block(section_block->blocks[i]);
                break;

        }
    }

    char *data_in_section_block =
        strarrcat(translated_blocks, section_block->blocks_count);

    unsigned int data_in_section_block_size = strlen(data_in_section_block);

    ret = stralloc(
            HTML_SECTION_FORMAT_SIZE
            + dicount(toc_node->id)
            + title_size
            + data_in_section_block_size
            );

    sprintf(ret, HTML_SECTION_FORMAT,
            section_block->title,
            data_in_section_block);

    for (unsigned int i = 0; i < section_block->blocks_count; i++)
    {
        sfree(translated_blocks[i]);
    }
    sfree(translated_blocks);
    sfree(data_in_section_block);

    return ret;
}

char *fcd_st2html(fcd_root_block *root_block)
{
    char date_str[64];
    unsigned int title_size = strlen(root_block->title);
    unsigned int author_size = strlen(root_block->author);

    char **translated_sections =
        (char**)malloc(sizeof(char*) * root_block->sections_count);

    /*
     * its compile each section block in root_block->blocks[]
     */
    for (unsigned int i; i < root_block->sections_count; i++)
    {
        translated_sections[i] =
            _translate_section_block(root_block->sections[i],
                    root_block->toc->nodes[i]);
    }

    struct tm* tm_local = localtime(&root_block->date);
    strftime(date_str, 64, "%F", tm_local);

    char *data_in_root_block =
        strarrcat(translated_sections, root_block->sections_count);


    unsigned int data_in_root_block_size = strlen(data_in_root_block);

    char *ret = stralloc(
            BASE_HTML_FORMAT_SIZE 
            + title_size
            + data_in_root_block_size
            + author_size
            );

    sprintf(ret, BASE_HTML_FORMAT,
            BASE_CSS,
            root_block->title,
            data_in_root_block,
            root_block->author, date_str);

    for (unsigned int i = 0; i < root_block->sections_count; i++)
    {
        sfree(translated_sections[i]);
    }
    sfree(translated_sections);
    sfree(data_in_root_block);

    return ret;
}

