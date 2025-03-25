#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

#include "../include/token.h"
#include "../include/globalVars.h"
#include "../include/functions.h"
#include "../include/enums.h"

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

void loadFile(const char *fileName)
{
    FILE *file = fopen(fileName, "r");

    if(!file)
    {
        perror("Failed to open file");

        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);

    long long fileSize = ftell(file);

    fseek(file, 0, SEEK_SET);

    buffer = (char *) malloc(fileSize + 1);

    if(!buffer)
    {
        perror("Memory failure");

        fclose(file);

        exit(EXIT_FAILURE);
    }

    fread(buffer, 1, fileSize, file);

    buffer[fileSize] = '\0';

    fclose(file);
    
    currentChar = buffer;
}

int getNextToken()
{
    int state = 0;

    char ch, *startChar;

    int memSize = 0;

    token *tk;

    while(1)
    { 
        ch = *currentChar;

        switch(state)
        {
            case 0:
            {
                if(isalpha(ch) || ch == '_')
                {
                    startChar = currentChar;

                    currentChar++;

                    state = 1;
                }

                break;
            }

            case 1:
            {
                if(isalpha(ch) || ch == '_')
                {
                    currentChar++;
                }
                else
                {
                    state = 2;
                }
                
                break;
            }

            case 2:
            {
                memSize = currentChar - startChar;

                switch(memSize)
                {
                    case 2:
                    {
                        if(!memcmp(startChar,"if", 2))
                        {
                            tk = insert_token(IF,0);
                        }
                        break;
                    }

                    case 3:
                    {
                        if(!memcmp(startChar,"for", 3))
                        {
                            tk = insert_token(FOR, 0);
                        }
                        else
                        {
                            if (!memcmp(startChar,"int",3)) 
                            {
                                tk = insert_token(INT, 0);
                            }
                        }
                        break;
                    }

                    case 4:
                    {
                        if(!memcmp(startChar,"char", 4))
                        {
                            tk = insert_token(CHAR, 0);
                        }
                        else 
                        {
                            if(!memcmp(startChar,"else",4))
                            {
                                tk = insert_token(ELSE, 0);
                            }
                        }
                    }

                    case 5:
                    {
                        if(!(memcmp(startChar, "break", 5)))
                        {
                            tk = insert_token(BREAK,0);
                        }
                        break;
                    }
                } 
            }
        }
    }
}
