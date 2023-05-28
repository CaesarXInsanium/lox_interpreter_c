#pragma once
#include "clox_error.h"
#include "clox_linked_list.h"
#include "clox_object.h"
#include "clox_string.h"
#include "clox_token.h"
#include "clox_token_type.h"
#include <stddef.h>
#include <stdint.h>

typedef struct {
  String *source;
  DList *tokens;
  size_t start;
  size_t current;
  size_t line;
  DList *result;
}ScannerState ;

// functions

// initializes the scanner and commences the process of scanning
void scanner_init(ScannerState *scanner, String *source);
// only function that is meant to be used
DList *scan_tokens(ScannerState *scanner);

void scan_token(String *scanner);

void number(ScannerState *scanner);
void string(ScannerState *scanner);
bool match(ScannerState *scanner, char expected);
void identifier(ScannerState *scanner);

char advance(ScannerState *scanner);

void add_token_obj(ScannerState *scanner, TOKEN_E type, LoxObject *obj);
void add_token(ScannerState *scanner, TOKEN_E type);

bool is_at_end(ScannerState *scanner);

bool is_alpha(char c);
bool is_number(char c);
bool is_alphanumeric(char c);

char peek(ScannerState *self);

char peek_next(ScannerState *self);
