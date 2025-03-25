#ifndef _ENUMS_H
#define _ENUMS_H

extern enum identifier
{
    ID
};

extern enum keyword
{
    BREAK,
    CHAR,
    DOUBLE,
    ELSE,
    FOR,
    IF,
    INT,
    RETURN,
    STRUCT,
    VOID,
    WHILE
};

extern enum constans
{
    CT_INT,
    CT_REAL,
    CT_CHAR,
    CT_STRING
};

extern enum delimiter
{
    COMMA,
    SEMICOLON,
    LPAR,
    RPAR,
    LBRACKET,
    RBRACKET,
    LACC,
    RACC
};

extern enum opreators
{
    ADD,
    SUB,
    MUL,
    DIV,
    DOT,
    AND,
    OR,
    NOT,
    ASSIGN,
    EQUAL,
    NOTEQ,
    LESS,
    LESSEQ,
    GREATER,
    GREATEREQ 
};

extern enum sugar
{
    SPACE,
    LINECOMMENT,
    COMMENT
};

#endif
