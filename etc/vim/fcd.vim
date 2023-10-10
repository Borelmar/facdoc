let b:current_syntax = "fcd"

let l_end = "(end(_)?)"
let r_end = "((_)?end)"
let document =  "(doc(ument)?)"
let e_document = "(${l_end}${document})|(${document}${r_end})"
let include =   "(include)"
let section =   "(sec(tion)?)"
let e_section = "(${l_end}${section})|(${section}${r_end})"

let link =      "(link)"
let image =     "(img|image)"
let shell =     "(sh|shell|cmd|command)"

let text =      "(t(e)?xt)"
let e_text =    "(${l_end}${text})|(${text}${r_end})"
let code =      "(code)"
let e_code =    "(${l_end}${code})|(${code}${r_end})"
let table =     "(table)"
let e_table =   "(${l_end}${table})|(${table}${r_end})"
let list =      "(list)"
let e_list =    "(${l_end}${list})|(${list}${r_end})"
let csv_table = "(csv_table)"

let row =       "(row)"
let e_row =     "(${l_end}${row})|(${row}${r_end})"

let cell =      "(cell|cl)"
let e_cell =    "(${l_end}${cell})|(${cell}${r_end})"
let header =    "(header|head|hd)"
let e_header =  "(${l_end}${header})|(${header}${r_end})"

let bold =          "(bold|b)"
let e_bold =        "(${l_end}${bold})|(${bold}${r_end})"
let italic =        "(italic|i)"
let e_italic =      "(${l_end}${italic})|(${italic}${r_end})"
let underline =     "(underline|uline|u)"
let e_underline =   "(${l_end}${underline})|(${underline}${r_end})"
let mark =          "(mark|m)"
let e_mark =        "(${l_end}${mark})|(${mark}${r_end})"
let superscript =   "(superscript|sup)"
let e_superscript = "(${l_end}${superscript})|(${superscript}${r_end})"
let subscript =     "(subscript|sub)"
let e_subscript =   "(${l_end}${subscript})|(${subscript}${r_end})"
let delete =        "(delete|del|d)"
let e_delete =      "(${l_end}${delete})|(${delete}${r_end})"

syn keyword fcdKeyword document include section link image shell text code table list csv_table row cell header bold italic underline mark superscript subscript delete e_document e_include e_section e_link e_image e_shell e_text e_code e_table e_list e_csv_table e_row e_cell e_header e_bold e_italic e_underline e_mark e_superscript e_subscript e_delete


syn match fcdComment "/\*.*\*/"
syn match fcdString '\'[^"]*\''

hi def link fcdKeyword Keyword
hi def link fcdComment Comment
hi def link fcdString String
