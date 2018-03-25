/**
 * The Ion Programming language
 * https://www.youtube.com/watch?v=0woxSWjWsb8: min 12
 */
#include <stdio.h>

int main(int argc, char** argv) {
  for (int i = 0; i < argc; ++i) {
    printf("%s\n", argv[i]);
  }
  return 0;
}
