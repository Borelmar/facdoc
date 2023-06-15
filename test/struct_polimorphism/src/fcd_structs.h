#ifndef _STRUCTS_H
#define _STRUCTS_H

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
    BLOCK_T_LINK
} fcd_block_t;

/* MODIFERS */
typedef
    struct
{
    fcd_tmod_t type;
    unsigned int offset_start;
    unsigned int offset_end;
} fcd_text_modifer;

typedef
    struct
{
    unsigned int offset_start;
    unsigned int offset_end;
} fcd_code_mark;


/* BLOCKS */
typedef
    struct
{
    fcd_block_t type;
    fcd_text_modifer ** modifers;
    char *data;
} fcd_text_block;

typedef
    struct
{
    fcd_block_t type;
    fcd_code_mark ** marks;
    char *data;
} fcd_code_block;

typedef
    struct
{
    fcd_block_t type;
    char *alt; /* alternative text for image */
    char *path;
} fcd_image_block;

typedef
    struct
{
    fcd_block_t type;
    char* title;
    unsigned int child_blocks_count;
    void ** child_blocks;
} fcd_section_block;

/* This strcut need for get type of block */
typedef
    struct
{
    fcd_block_t type;
} fcd_base_block;

typedef
    struct
{
    char *doc_title;
    int date;
    unsigned int blocks_count;
    fcd_section_block ** blocks;
} fcd_root_block;

#endif /* _STRUCTS_H */
