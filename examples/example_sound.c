/*
this is a simple sound example

NATIVE:
clang examples/example_sound.c -o example_sound

WASM:
clang --target=wasm32-wasi --sysroot=/wasi-sdk/sysroot \
  examples/example_sound.c -o example_sound.wasm
*/

int main(int argc, char* argv[]) {
  return 0;
}