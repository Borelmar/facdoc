#include <stdio.h>

#define TMOD_T_BOLD         0x01
#define TMOD_T_ITALIC       0x02
#define TMOD_T_UNDERLINE    0x03
#define TMOD_T_MARK         0x04
#define TMOD_T_SUPERSCRIPT  0x05
#define TMOD_T_SUBSCRIPT    0x06
#define TMOD_T_LINK         0x07
#define TMOD_T_DEL          0x08

struct toc_item
{
    unsigned int ordinal_num;
};

/* tmod_t - text modification type */
typedef char tmod_t;

struct fcd_text_modifer
{
    tmod_t type;
    unsigned int offset_start;
    unsigned int offset_end;
};

struct fcd_toc_entity
{
    toc_item ** toc_root;
};

struct fcd_title_entity
{
    char *text;
};

struct fcd_code_entity
{
    char *body;
};

struct fcd_text_entity
{
    char *toc_name;
    char *text;
    unsigned int modifers_count;
    fcd_text_modifer ** modifers;
};

struct fcd_image_entity
{
    unsigned int ordinal_num;
    char *alt; /* alternative text for image */
    char *path;
};

struct fcd_title_entity
{
    unsigned int ordinal_num;
    char *text;
};

struct fcd_block {
    char* title;
    unsigned int ordinal_num;
    struct fcd_blocks** blocks;
    void* entity;
};

typedef struct {
    struct fcd_block ** blocks;
} fcd_root_struct;
