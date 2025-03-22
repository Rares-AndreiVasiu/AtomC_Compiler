#ifndef _TOKEN_H
#define _TOKEN_H

typedef struct _token
{
    int code;

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
