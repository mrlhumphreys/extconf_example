#include <stdlib.h>
#include <stdio.h>

char* c_string(char* value) {
  char* out = (char*)malloc(256 * sizeof(char));
  sprintf(out, "String: '%s'", value);
  return out;
}

int c_number(int value) {
  return value + 1;
}

int c_boolean(int value) {
  if (value == 0) {
    return 1;
  } else {
    return 0;
  }
}
