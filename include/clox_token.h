#ifndef CLOX_TOKEN_H
#define CLOX_TOKEN_H

#include "clox_string.h"
#include "clox_token_type.h"
#include <stdint.h>

typedef struct{
  TOKEN_E type;
  String lexeme;
  void *object;
  int line;
} Token;

Token newToken(TOKEN_E ty, String lex, void *obj, int line);

#endif
