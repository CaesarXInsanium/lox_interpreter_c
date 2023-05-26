#include "run.h"
#include "clox_error.h"
#include "clox_string.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CLOX_ERROR run_file(const char *path) {
  FILE *fp = open_path(path);
  if (had_error) {
    goto HandleError;
  }
  String source;
  load_source(fp, &source);
  if (had_error)
    goto HandleError;
  run(source);
HandleError:
  report(stderr, 1, String_fromCharArray("path"), explain_error(error_type));
  return error_type;
}
CLOX_ERROR run(String source) {
  printf("Running this bullshit: %p\n", (void *)&source);
  return CLOX_SUCCESS;
}
CLOX_ERROR run_prompt(void) {

  while (1) {
    fprintf(stdout, "> ");
    String line;
    read_line(&line);
    if (String_isEmpty(line)) {
      break;
    }
    run(line);
    had_error = false;
  }
  return error_type;
}

FILE *open_path(const char *path) {
  if (strlen(path) == 0) {
    run_prompt();
  }
  FILE *result = fopen(path, "r");
  if (result == NULL) {
    had_error = true;
    error_type = CLOX_ERROR_FILE_NOT_FOUND;
  }
  return result;
}

void load_source(FILE *fp, String *target) {
  // go to end of file, if successful fseek returns 0
  if (fseek(fp, 0L, SEEK_END) == 0) {
    // determine where in file we are
    uint64_t file_size = ftell(fp);
    target->buffer = malloc(sizeof(char) * (file_size + 1));

    if (fseek(fp, 0L, SEEK_SET) != 0) {
      goto HandleIOError;
    }
    size_t new_len = fread(target->buffer, sizeof(char), file_size, fp);
    if (ferror(fp) != 0) {
      goto HandleIOError;
    }
    target->buffer[new_len++] = '\0';
    target->len = strlen(target->buffer);
    target->capacity = file_size + 1;
    fclose(fp);
    return;
  } else {
    goto HandleIOError;
  }
HandleIOError:
  fclose(fp);
  fprintf(stderr, "Failed read file for some reason\n");
  exit(EXIT_FAILURE);
}

void read_line(String *target) {
  char buf[MAX_REPL_CHAR_SIZE];
  fgets(buf, MAX_REPL_CHAR_SIZE, stdin);
  int len = strlen(buf);
  target->buffer = malloc(sizeof(char) * len);
  strcpy(target->buffer, buf);
  target->len = len;
  target->capacity = len;
}
