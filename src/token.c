#include "clox_token.h"
#include "clox_token_type.h"

Token newToken(TOKEN_E ty, String lex, void *obj, int line) {
  Token result;
  result.type = ty;
  result.lexeme = lex;
  result.object = obj;
  result.line = line;
  return result;
}
