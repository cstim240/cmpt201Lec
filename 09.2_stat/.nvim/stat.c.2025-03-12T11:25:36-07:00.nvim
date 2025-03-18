#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  // use stat() to display if path is file or directory
  char *path = argv[1];
  struct stat st;

  stat(path, &st);
  if (S_ISREG(st.st_mode)) {
    printf("Regular file\n");
  } else if (S_ISDIR(st.st_mode)) {
    printf("Directory\n");
  } else {
    printf("Other!??\n");
  }
}
