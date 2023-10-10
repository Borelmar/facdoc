#ifndef ___TRANSLATORS___H___
#define ___TRANSLATORS___H___

typedef struct {
    char *name;
    char *description;
    char *start_point;
} fcd_translator_t;

#ifndef IT__TRANSLATORS_C__
extern int reg_translator(fcd_translator_t *translator);
#endif

#endif /* ___TRANSLATORS___H___ */
