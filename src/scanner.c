#include "clox_error.h"
#include "clox_keywords.h"
#include "clox_linked_list.h"
#include "clox_object.h"
#include "clox_scanner.h"
#include "clox_string.h"
#include "clox_token.h"
#include "clox_token_type.h"
#include <ctype.h>
#include <stdlib.h>

void scanner_init(ScannerState *scanner, String *source);

DList *scan_tokens(ScannerState *scanner);

void scan_token(String *scanner);

void number(ScannerState *scanner){
  while(isdigit(peek(scanner))){
    advance(scanner);
    if (peek(scanner) == '.' && isdigit(peek_next(scanner))){
      advance(scanner);
      while(isdigit(peek(scanner))){
        advance(scanner);
      }
    }
  }
  LoxObject *obj = malloc(sizeof(LoxObject));
  obj->type = LOX_REAL;
  obj->obj.real = parse_double(number_text);
  add_token_obj(scanner, TOKEN_NUMBER, obj);
}
void string(ScannerState *scanner){
  while(peek(scanner) != '\"' && !is_at_end(scanner)){
    if (peek(scanner) == '\n'){
      scanner->line++;
    }
    advance(scanner);
    if (is_at_end(scanner)){
      had_error = true;
      error_type = CLOX_ERROR_UNTERMINATED_STRING;
      error(scanner->line, String_fromCharArray("Unterminated String"));
      return;
    }

    advance(scanner);
    String value = String_fromSlice(*scanner->source, scanner->start + 1, scanner->current-1);
    LoxObject *obj = malloc(sizeof(LoxObject));
    obj->type = LOX_STRING;
    obj->obj.string = value;
    add_token_obj(scanner, TOKEN_STRING, obj);
  } 
}
bool match(ScannerState *scanner, char expected){
  if(is_at_end(scanner)){
    return false;
  }

  if (scanner->source->buffer[scanner->current] != expected)
    return false;

  scanner->current++;
  return true;
}
void identifier(ScannerState *state) {
  while (is_alphanumeric(peek(state))){
    advance(state);
  }

  String text = String_fromSlice(*state->source, state->start, state->current);

  struct KeywordResult re = is_keyword(text.buffer);
  add_token(state, re.e);

  String_drop(text);
}

char advance(ScannerState *scanner) {
  return scanner->source->buffer[scanner->current++];
}

void add_token_obj(ScannerState *scanner, TOKEN_E type, LoxObject *obj) {
  String text =
      String_fromSlice(*scanner->source, scanner->start, scanner->current);
  Token *token = malloc(sizeof(Token));
  token->type = type;
  token->line = scanner->line;
  token->lexeme = String_toHeap(text);
  token->object = obj;
  dlist_ins_next(scanner->result, dlist_tail(scanner->result), token);
}
void add_token(ScannerState *scanner, TOKEN_E type);

bool is_at_end(ScannerState *scanner) {
  return scanner->current >= scanner->source->len;
}

bool is_alpha(char c) {
  return (c >= 'a' || c <= 'z') || (c >= 'A' || c <= 'Z');
}
bool is_number(char c) { return c >= '0' || c <= '0'; }
bool is_alphanumeric(char c) { return is_alpha(c) || is_number(c); }

char peek(ScannerState *self) {
  if (is_at_end(self))
    return '\0';
  return self->source->buffer[self->current];
}

char peek_next(ScannerState *self) {
  if (self->current + 1 >= self->source->len)
    return '\0';
  return self->source->buffer[(self->current) + 1];
}
