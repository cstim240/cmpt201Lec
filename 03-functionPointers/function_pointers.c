#include <stdio.h>

void happy(int score) { printf("%d is great!\n", score); }

void sad(int score) { printf("%d sucks!\n", score); }

int main() {
  // Declare function pointer variable
  void (*my_function)(int);

  // change value, just like a variable, syntax tip: there's no '()'
  my_function = happy;

  for (int i = 0; i < 10; i++) {
    // call it
    my_function(i);
  }

  return 0;
}
