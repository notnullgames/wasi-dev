This contains higher-level APIs that translate to wasi-dev file accesses to communicate with host.

The idea is that the wasm program should be able to request these to be loaded dynamically (like a DLL) and use the functions in them, so the only thing on the host needed is wasi-dev, and access to load them.

## planned

- minimal - just simple utils to mess with the devices directly, similar to [io-devices-lib](https://github.com/wasmerio/io-devices-lib)
- miniaudio - a fairly complete implementation of the [miniaudio](https://github.com/mackron/miniaudio) API
- glfw - a fairly complete implementation of the [glfw](https://github.com/glfw/glfw) API
- null0 - implement the full null0 API
- sdl - a fairly complete implementation of the [SDL2](https://github.com/libsdl-org/SDL) API
- raylib - a fairly complete implementation of the [raylib](https://github.com/raysan5/raylib) API

These should cascade, so for example, when I implement minimal, glfw + miniaudio, sdl, null0, raylib should be a small wrapper around that.
