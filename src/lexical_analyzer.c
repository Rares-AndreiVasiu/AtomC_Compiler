#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "../include/token.h"

#include "../include/functions.h"

void error(char *fmt, ...)
{
    va_list va;

    va_start(va, fmt);

    fprintf(stderr, "Trouble: ");

    vfprintf(stderr, fmt, va);

    fputc('\n', stderr);

    va_end(va);

    exit(-1);
}

void token_error(token *token, char *fmt, ...)
{
    va_list va;

    va_start(va, fmt);

    fprintf(stderr, "error at %d: ", token -> line);

    vfprintf(stderr, fmt, va);

    fputc('\n', stderr);

    va_end(va);

    exit(-1);
}

token *insert_token(int code, int line)
{
    token *temp = malloc(sizeof(token));

    if(!temp)
    {
        return NULL;
    }

    temp -> code = code;

    temp -> line = line;

    temp -> next = NULL;
}

int main()
{
    return 0;
}
