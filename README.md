> **WARNING** This is very incomplete. I am basically using this repo to record some ideas about better I/O for WASI/wasm, but it's not at all complete.

The idea is that the wasm program should be able to request higher-level APIs to be loaded dynamically (like a DLL) and use the functions in them, so the only thing on the host needed is wasi-dev (linux-like devices: `/dev/fb0`, `/dev/dsp0`, `/dev/input/`) and access to load them.

The eventual idea is to create a few hosts (nodejs, web, and native) and some adapter WASM files that will translate higher-level APIs (like glfw or SDL) into these device file-access calls.

Intiially, I am just getting basic demos and a library for adding sound support.
