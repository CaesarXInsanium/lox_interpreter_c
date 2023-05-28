#include "clox_string.h"
#include "clox_token.h"
#include "clox_token_type.h"
#include <stdlib.h>

Token newToken(TOKEN_E ty, String lex, void *obj, int line) {
  Token result;
  result.type = ty;
  result.lexeme = String_toHeap(lex);
  result.object = obj;
  result.line = line;
  return result;
}

void Token_destroy(Token *e){
  String_destroy(e->lexeme);
  free(e);
}
