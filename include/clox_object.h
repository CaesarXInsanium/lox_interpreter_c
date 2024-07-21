#pragma once

#include "clox_string.h"

typedef enum {
  LOX_NULL,
  LOX_STRING,
  LOX_INT,
  LOX_REAL,
} LoxObjectType;

typedef union {
  String string;
  int integer;
  double real;
} LoxObjectStorage;

typedef struct{
  LoxObjectType type;
  LoxObjectStorage obj;
} LoxObject;

void LoxObject_destroy(LoxObject *obj);

double parse_double(const String str);
