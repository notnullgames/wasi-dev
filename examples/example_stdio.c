/*
simple example that just prints text

NATIVE:
clang -o example_stdio examples/example_stdio.c

WASM:
WASI_SDK="${HOME}/wasi-sdk-21.0"
${WASI_SDK}/bin/clang -o example_stdio.wasm examples/example_stdio.c

*/

#include <stdio.h>

int main() {
  printf("Hello from wasidev\n");
  return 0;
}
