> **WARNING** THis is very incomplete. I am basically using this repo to record some ideas about better I/O for WASI/wasm, but it's not at all complete.

git status so you can build browser/native WASM that interacts with a few device files (simialr to linux's `/dev/dsp0`, `/dev/fb0` and `/dev/uinput`) without emscripten or any assumptions about how the host works.

The eventual idea is to create a few hosts (nodejs, web, and native) and some adapter WASM files that will translate higher-level APIs (like glfw or SDL) into these device file-access calls.

Intiially, I am just getting basic demos and a library for adding sound support.
