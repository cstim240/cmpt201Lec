#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool find_first_digit(char *data, int n, char **ppdigit) {
  for (int i = 0; i < n; i++) {
    if (isdigit(data[i])) {
      *ppdigit = &data[i];
      return true;
    }
  }
  return false;
}

int main() {
  char *data = "I wa5 h3h3!\n";
  char *pfirst_digit = NULL;

  if (find_first_digit(data, strlen(data), &pfirst_digit)) {
    printf("Found digit: %c\n", *pfirst_digit);
  } else {
    printf("Found no digits.\n");
  }
}
