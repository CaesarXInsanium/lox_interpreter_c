#pragma once
#include "clox_string.h"
#include "clox_error.h"
#include "clox_token.h"
#include "clox_token_type.h"

static int scanner_start;
static int scanner_current;
static int scanner_line;
