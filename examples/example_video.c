/*
this is a simple framebuffer example

NATIVE:
clang examples/example_video.c -o example_video

WASM:
clang --target=wasm32-wasi --sysroot=/wasi-sdk/sysroot \
  examples/example_video.c -o example_video.wasm
*/

int main(int argc, char* argv[]) {
  return 0;
}