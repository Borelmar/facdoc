
#ifndef _FCD_SYNTAX_H_
#define _FCD_SYNTAX_H_

enum fcd_block_types
{
    BLOCK_T_BLOCK,
    BLOCK_T_TITLE,
    BLOCK_T_TEXT,
    BLOCK_T_IMAGE,
    BLOCK_T_CODE,
    BLOCK_T_LINK,
    BLOCK_T_TEXT_MODIFER
};

typedef enum fcd_block_types
    fcd_block_type;

#endif /* _FCD_SYNTAX_H_ */
