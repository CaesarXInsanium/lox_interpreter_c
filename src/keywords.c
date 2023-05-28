#include "clox_keywords.h"
#include "clox_token.h"
#include "clox_token_type.h"
#include <string.h>

struct KeywordResult is_keyword(char *str) {
  struct KeywordResult result;
  if (strcmp(str, "and")) {
    struct KeywordResult result = {.b = true, .e = TOKEN_AND};
    return result;
  } else if (strcmp(str, "or")) {
    struct KeywordResult result = {.b = true, .e = TOKEN_OR};
    return result;
  } else if (strcmp(str, "class")) {
    struct KeywordResult result = {.b = true, .e = TOKEN_CLASS};
    return result;
  } else if (strcmp(str, "else")) {
    struct KeywordResult result = {.b = true, .e = TOKEN_ELSE};
    return result;
  } else if (strcmp(str, "false")) {
    struct KeywordResult result = {.b = true, .e = TOKEN_FALSE};
    return result;
  } else if (strcmp(str, "for")) {
    struct KeywordResult result = {.b = true, .e = TOKEN_FOR};
    return result;
  } else if (strcmp(str, "fun")) {
    struct KeywordResult result = {.b = true, .e = TOKEN_FUN};
    return result;
  } else if (strcmp(str, "if")) {
    struct KeywordResult result = {.b = true, .e = TOKEN_IF};
    return result;
  } else if (strcmp(str, "nil")) {
    struct KeywordResult result = {.b = true, .e = TOKEN_NIL};
    return result;
  } else if (strcmp(str, "print")) {
    struct KeywordResult result = {.b = true, .e = TOKEN_PRINT};
    return result;
  } else if (strcmp(str, "return")) {
    struct KeywordResult result = {.b = true, .e = TOKEN_RETURN};
    return result;
  } else if (strcmp(str, "super")) {
    struct KeywordResult result = {.b = true, .e = TOKEN_SUPER};
    return result;
  } else if (strcmp(str, "this")) {
    struct KeywordResult result = {.b = true, .e = TOKEN_THIS};
    return result;
  } else if (strcmp(str, "true")) {
    struct KeywordResult result = {.b = true, .e = TOKEN_TRUE};
    return result;
  } else if (strcmp(str, "var")) {
    struct KeywordResult result = {.b = true, .e = TOKEN_VAR};
    return result;
  } else if (strcmp(str, "while")) {
    struct KeywordResult result = {.b = true, .e = TOKEN_WHILE};
    return result;
  }
  result.b = false;
  result.e = TOKEN_IDENTIFIER;
  return result;
}
