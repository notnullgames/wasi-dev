This is a WASI-based "device layer" so you can build browser/native WASM that interacts with a few device files (simialr to linux's `/dev/dsp0`, `/dev/fb0` and `/dev/uinput`) without emscripten or any assumptions about how the host works.

The eventual idea is to create a couple hosts (native and web) and and some adapter WASM files that will translate higher-level APIs (like glfw or SDL) into these device file-access calls.
