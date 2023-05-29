#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_

char *BASE_CSS = "\
body{\
margin: 20px;\
}\
pre{\
background-color: #F0F0F0;\
border-radius: 4px;\
padding: 5px;\
display: inline-block;\
white-space: pre-wrap\
}\
";

/*
 * & = &amp;
 * < = &lt;
 * > = &gt;
 */

char *BASE_HTML = "\
<!DOCTYPE html>\
<html lang=\"en\">\
<head>\
<meta charset=\"UTF-8\"/>\
<meta name=\"viewport\" content=\"width=device-width,initial-scale=1.0\"/>\
<link rel=\"stylesheet\" href=\"style.css\"/>\
<title>Browser</title>\
<style>\
</style>\
</head>\
<body>\
<pre></pre>\
</body>\
</html>";

#endif /* _TEMPLATE_H_ */
