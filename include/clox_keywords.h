#pragma once

#include "clox_token_type.h"
#include <stdbool.h>
#include <stddef.h>

struct KeywordResult {
  bool b;
  TOKEN_E e;
};

struct KeywordResult is_keyword(char *str);
