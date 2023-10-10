/* 
 * This file a store main fcd format structs.
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

#ifndef _FCD_H
#define _FCD_H

#define FCD_FORMAT_VERSION 1.0

typedef enum 
{
    TMOD_T_BOLD,
    TMOD_T_ITALIC,
    TMOD_T_UNDERLINE,
    TMOD_T_MARK,
    TMOD_T_SUPERSCRIPT,
    TMOD_T_SUBSCRIPT,
    TMOD_T_LINK,
    TMOD_T_DEL

} fcd_tmod_t;


typedef enum 
{
    BLOCK_T_SECTION,
    BLOCK_T_TEXT,
    BLOCK_T_IMAGE,
    BLOCK_T_CODE,
    BLOCK_T_NOTE,
    BLOCK_T_LINK,
    BLOCK_T_TABLE

} fcd_block_t;


/* MODIFERS */
typedef
    struct
{
    fcd_tmod_t type;
    unsigned int offset_start;
    unsigned int offset_end;
    void *extra_data;
} fcd_text_modifer;


typedef struct
{
    unsigned int offset_start;
    unsigned int offset_end;
} fcd_code_mark;


/* BLOCKS */
typedef struct
{
    fcd_block_t type;
    unsigned int modifers_count;
    fcd_text_modifer **modifers;
    char *data;

} fcd_text_block;

typedef struct
{
    fcd_block_t type;
    char *link;
    char *text;

} fcd_link_block;

typedef struct
{
    fcd_block_t type;
    char *text;

} fcd_note_block;


typedef struct
{
    fcd_block_t type;
    char **data_table;

} fcd_table_block;


typedef struct
{
    fcd_block_t type;
    fcd_code_mark **marks;
    char *data;

} fcd_code_block;


typedef struct
{
    fcd_block_t type;
    char *alt; /* alternative text */
    char *path;
    char *data;

} fcd_image_block;


typedef struct
{
    fcd_block_t type;
    char *title;
    unsigned int id;
    unsigned int blocks_count;
    void **blocks;

} fcd_section_block;


typedef struct
{
    unsigned int id;
    unsigned int nodes_count;
    void **nodes;

} fcd_toc_node;


typedef struct
{
    unsigned int nodes_count;
    fcd_toc_node **nodes;

} fcd_toc;


/* This strcut need for get type of block */
typedef struct /* fcd_base_block */
{
    fcd_block_t type;
} fcd_base_block;

typedef struct /* fcd_root_block */
{
    char *title;
    char *author;
    time_t date;
    fcd_toc *toc;
    unsigned int sections_count;
    fcd_section_block ** sections;

} fcd_root_block;


int fcd_check_syntax(const char *data);

int fcd_free(fcd_root_block *root);

#endif /* _FCD_H */
