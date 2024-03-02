/*
simple example that just reads file

NATIVE:
clang -o example_files examples/example_files.c

WASM:
WASI_SDK="${HOME}/wasi-sdk-21.0"
${WASI_SDK}/bin/clang -o example_files.wasm examples/example_files.c

*/

#include <stdio.h>

int main(int argc, char* argv[]) {
  FILE* f = fopen("test/test.txt", "r");
  int ch;
  do {
    ch = fgetc(f);
    if (ch != EOF) {
      fputc(ch, stdout);
    }
  } while (ch != EOF);
  fclose(f);
  return 0;
}
