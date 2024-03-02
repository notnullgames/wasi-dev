/*
this is a simple demo that can read keybaord input

NATIVE:
clang examples/example_input.c -o example_input

WASM:
clang --target=wasm32-wasi --sysroot=/wasi-sdk/sysroot \
  examples/example_input.c -o example_input.wasm
*/

int main(int argc, char* argv[]) {
  return 0;
}