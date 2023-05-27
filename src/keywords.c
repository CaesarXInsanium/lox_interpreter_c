#include "clox_keywords.h"
#include "clox_token.h"
#include "clox_token_type.h"

const struct KeyWord KeyWord_AND = {
  .ty  = TOKEN_AND,
  .word = "and"
};
const struct KeyWord KeyWord_OR;
const struct KeyWord KeyWord_CLASS;
const struct KeyWord KeyWord_ELSE;
const struct KeyWord KeyWord_FALSE;
const struct KeyWord KeyWord_FOR;
const struct KeyWord KeyWord_FUN;
const struct KeyWord KeyWord_IF;
const struct KeyWord KeyWord_NIL;
const struct KeyWord KeyWord_PRINT;
const struct KeyWord KeyWord_RETURN;
const struct KeyWord KeyWord_SUPER;
const struct KeyWord KeyWord_THIS;
const struct KeyWord KeyWord_TRUE;
const struct KeyWord KeyWord_VAR;
const struct KeyWord KeyWord_WHILE;
