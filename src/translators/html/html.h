/* 
 * This file store the html formats for fcd2html translator.
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

#ifndef _HTML__FORMATS___H_
#define _HTML__FORMATS___H_

#define SUPPORTED_HTML_VERSION 5
#define SUPPORTED_CSS_VERSION 3

char *BASE_HTML_FORMAT = "\
<!DOCTYPE html>\
<html lang=\"en\">\
<head>\
<meta charset=\"UTF-8\"/>\
<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"/>\
<style>\
%s\
</style>\
<title>%s</title>\
</head>\
<body>\
</body>\
<footer>\
Copyright %s\
</footer>\
</html>";
unsigned int BASE_HTML_FORMAT_SIZE = sizeof(BASE_HTML_FORMAT) - 6;



char *HTML_SECTION_FORMAT = "\
<div class=\"block\" id=\"%s\">\
<h3 class=\"title\">%s</h3>\
%s\
</div>";
unsigned int HTML_SECTION_FORMAT_SIZE = sizeof(HTML_SECTION_FORMAT) - 6;



char *HTML_NEW_LINE_FORMAT = "<br>";
unsigned int HTML_NEW_LINE_FORMAT_SIZE = sizeof(HTML_NEW_LINE_FORMAT);



char *HTML_CODE_FORMAT = "<pre class=\"code\">%s</pre>";
unsigned int HTML_CODE_FORMAT_SIZE = sizeof(HTML_CODE_FORMAT) - 2;



char *HTML_TEXT_FORMAT = "<pre class=\"text\">%s</pre>";
unsigned int HTML_TEXT_FORMAT_SIZE = sizeof(HTML_TEXT_FORMAT) - 2;



char *HTML_IMAGE_PATH_STORE_FORMAT = "\
<img src=\"%s\" height=\"300\" alt=\"%s\">";
char *HTML_IMAGE_BASE64_STORE_FORMAT = "\
<img src=\"data:image/png;base64, %s\" height=\"300\" alt=\"%s\">";



char *HTML_TABLE_FORMAT = "<table>%s</table>";
unsigned int HTML_TABLE_FORMAT_SIZE = sizeof(HTML_TABLE_FORMAT) - 2;

char *HTML_TABLE_LINE_FORMAT = "<tr>%s</tr>";
unsigned int HTML_TABLE_LINE_FORMAT_SIZE = sizeof(HTML_TABLE_LINE_FORMAT) - 2;

char *HTML_TABLE_HEAD_FIELD_FORMAT = "<th>%s</th>";
unsigned int HTML_TABLE_HEAD_FIELD_FORMAT_SIZE
    = sizeof(HTML_TABLE_HEAD_FIELD_FORMAT) - 2;

char *HTML_TABLE_FIELD_FORMAT = "<td>%s</td>";
unsigned int HTML_TABLE_FIELD_FORMAT_SIZE
    = sizeof(HTML_TABLE_FIELD_FORMAT) - 2;



/* for text modifers */
char *HTML_TMOD_BOLD_FMT = "<b>%s</b>";
unsigned int HTML_TMOD_BOLD_FMT_SIZE = sizeof(HTML_TMOD_BOLD_FMT) - 2;

char *HTML_TMOD_ITALIC_FMT = "<i>%s</i>";
unsigned int HTML_TMOD_ITALIC_FMT_SIZE = sizeof(HTML_TMOD_ITALIC_FMT) - 2;

char *HTML_TMOD_UNDERLINE_FMT = "<u>%s</u>";
unsigned int HTML_TMOD_UNDERLINE_FMT_SIZE =
        sizeof(HTML_TMOD_UNDERLINE_FMT) - 2;

char *HTML_TMOD_MARK_FMT = "<mark>%s</mark>";
unsigned int HTML_TMOD_MARK_FMT_SIZE = sizeof(HTML_TMOD_MARK_FMT) - 2;

char *HTML_TMOD_SUPERSCRIPT_FMT = "<sup>%s</sup>";
unsigned int HTML_TMOD_SUPERSCRIPT_FMT_SIZE =
        sizeof(HTML_TMOD_SUPERSCRIPT_FMT) - 2;

char *HTML_TMOD_SUBSCRIPT_FMT = "<sub>%s</sub>";
unsigned int HTML_TMOD_SUBSCRIPT_FMT_SIZE =
        sizeof(HTML_TMOD_SUBSCRIPT_FMT) - 2;

char *HTML_LINK_FMT = "<a href=\"%s\">%s</a>";
unsigned int HTML_LINK_FMT_SIZE = sizeof(HTML_TMOD_LINK_FMT) - 4;

char *HTML_TMOD_DEL_FMT = "<del>%s</del>";
unsigned int HTML_TMOD_DEL_FMT_SIZE = sizeof(HTML_TMOD_DEL_FMT) - 2;


#endif /* _HTML__FORMATS___H_ */
