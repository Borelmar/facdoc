" Fcd syntax file
" Maintainer:   ungoogler@xgnu.org
" Version:      1.0
" Language:     fcd-1.0.0

if exists("b:current_syntax")
	let b:current_syntax = "fcd"
endif

syn match fcdKeyword /\<\(end_\?\(code\)\)\|\(\(code\)_\?end\)\>/
syn match fcdKeyword /\<\(end_\?\(header\|head\|hd\)\)\|\(\(header\|head\|hd\)_\?end\)\>/
syn match fcdKeyword /\<\(end_\?\(cell\|cl\)\)\|\(\(cell\|cl\)_\?end\)\>/
syn match fcdKeyword /\<\(end_\?\(row\)\)\|\(\(row\)_\?end\)\>/
syn match fcdKeyword /\<\(end_\?\(list\)\)\|\(\(list\)_\?end\)\>/
syn match fcdKeyword /\<\(end_\?\(table\)\)\|\(\(table\)_\?end\)\>/
syn match fcdKeyword /\<\(end_\?\(t\(e\)\?xt\)\)\|\(\(t\(e\)\?xt\)_\?end\)\>/
syn match fcdKeyword /\<\(end_\?\(superscript\|sup\)\)\|\(\(superscript\|sup\)_\?end\)\>/
syn match fcdKeyword /\<\(end_\?\(subscript\|sub\)\)\|\(\(subscript\|sub\)_\?end\)\>/
syn match fcdKeyword /\<\(end_\?\(delete\|del\)\)\|\(\(delete\|del\)_\?end\)\>/
syn match fcdKeyword /\<\(end_\?\(mark\|m\)\)\|\(\(mark\|m\)_\?end\)\>/
syn match fcdKeyword /\<\(end_\?\(underline\|uline\|u\)\)\|\(\(underline\|uline\|u\)_\?end\)\>/
syn match fcdKeyword /\<\(end_\?\(italic\|i\)\)\|\(\(italic\|i\)_\?end\)\>/
syn match fcdKeyword /\<\(end_\?doc\(ument\)\?\)\|\(doc\(ument\)\?_\?end\)\>/
syn match fcdKeyword /\<\(end_\?sec\(tion\)\?\)\|\(sec\(tion\)\?_\?end\)\>/
syn match fcdKeyword /\<\(end_\?\(bold\|b\)\)\|\(\(bold\|b\)_\?end\)\>/
syn match fcdKeyword /\<doc\(ument\)\?\>/
syn match fcdKeyword /\<sec\(tion\)\?\>/
syn match fcdKeyword /\<link\>/
syn match fcdKeyword /\<text\>/
syn match fcdKeyword /\<code\>/
syn match fcdKeyword /\<table\>/
syn match fcdKeyword /\<list\>/
syn match fcdKeyword /\<csv_table\>/
syn match fcdKeyword /\<row\>/
syn match fcdKeyword /\<\(cell\|cl\)>/
syn match fcdKeyword /\<\(header\|head\|hd\)\>/
syn match fcdKeyword /\<\(bold\|b\)\>/
syn match fcdKeyword /\<\(italic\|i\)\>/
syn match fcdKeyword /\<\(underline\|uline\|u\)\>/
syn match fcdKeyword /\<\(mark\|m\)\>/
syn match fcdKeyword /\<\(superscript\|sup\)\>/
syn match fcdKeyword /\<\(subscript\|sub\)\>/
syn match fcdKeyword /\<\(delete\|del\)\>/
syn match fcdKeyword /\<include\>/
syn match fcdKeyword /\<\(img\|image\)\>/

syn match fcdPare "(\|)"
syn match fcdString "\'[^"]*\'"
syn keyword fcdTodo contained TODO FIXME XXX NOTE
syn match fcdComment "/\*.*\*/" contains=fcdTodo

hi def link fcdPare Delimiter 
hi def link fcdKeyword Keyword
hi def link fcdComment Comment
hi def link fcdTodo Todo
hi def link fcdString String
