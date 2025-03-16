#ifndef _ENUMS_H
#define _ENUMS_H

enum identifier
{
    ID
};

enum keyword
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

enum constans
{
    CT_INT,
    CT_REAL,
    CT_CHAR,
    CT_STRING
};

enum delimiter
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

enum opreators
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

enum sugar
{
    SPACE,
    LINECOMMENT,
    COMMENT
};

typedef struct _token
{
    int code,

    union
    {
        //for id, CT_STRING
        char *text;
            
        // for CT_INT, CT_CHAR
        long int i;
        
        //for ct_real
        double r;
    };

    int line;

    struct _token *next;

}token;
#endif
