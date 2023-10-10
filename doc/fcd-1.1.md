## The fcd format manual
Fcd - Fast Create Documentation Format.
This is the lightweight struct format for write documentation.

### Fundamentals of Philosophy
- All it's be kind of kind block.
- And fcd is a hierarchy of blocks.
- It hierarchy of blocks describes the classic book structure.
- Don't be surprised by the limitations of using some blocks in other blocks.

### Block concept of fcd
A block, in the context of fcd, is some kind of function that has a body and
arguments.
```
(block 'arg1', 'arg2')
    ...hierarchy of blocks...
(block_end)
```
Block have the begin part and end part. Begining part open the body and take
args (if they are).

### Fcd document structure
The document starts at the root block, called - `document` or `doc`.
You can declare a sections and `include` blocks in `document` block.
Sections in fcd need for organize information and build table of contents.
Include - need for separating many section in one *.fcd* to many files.
Example of usage:
```
(document 'MyDoc')
    (section 'Chapter 1')
        (include './chptr1.1.fcd')
        (include './chptr1.2.fcd')
    (section_end)
    (include './chptr2.fcd')
(document_end)
```
But in the section you can using elements blocks, like text, table, image
and even code.


### Hello world document
```
(document 'MyFirstFcdDoc')
    (section 'Chpter 1')
        (text) Hello world (textend)
    (end_section)
(document_end)
```

---

## FCD reference 
### document block
args:
1. document name
2. author
3. write date
4. contact email or website or phone (for example)
closes: **yes**
```
(document 'document name' 'author' '99.99.9999' 'ex@mail.org')
    ...
(enddocument)
```
### section block
It block is base block for for other blocks (text, code, link, etc).
It also can recusivley have other section blocks.
args:
1. section name
closes: **yes**
```
(doc 'cafebabe')
    (section 'Chapter 1')
        (sec 'Chapter 1.1')
            ...
        (sec_end)
    (endsection)
(end_doc)
```
### include block
It need for separate big document to many files.
It block just paste data from file to main file at parsing.
args:
1. file name
closes: **no**
```
(doc 'foobar')
    (include 'chapter-1.fcd')
(enddoc)
```
