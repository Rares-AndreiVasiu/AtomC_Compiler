#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include "token.h"

#define SAFEALLOC(var, Type) if ((var = (Type *) malloc(sizeof(Type))) == NULL)error("memory error");

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

token *insertToken(int code, int line)
{
    token *temp;

    SAFEALLOC(temp, token);

    temp -> code = code;

    temp -> line = line;

    temp -> next = NULL;

    if(
}

#endif // !_TOKEN_FUNCTIONS_
