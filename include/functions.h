#ifndef  _FUNCTIONS_H
#define _FUNCTIONS_H

#include "token.h"

void error(char *fmt, ...);

void token_error(token *token, char *fmt, ...);

token *insert_token(int code, int line);

#endif 
