import fs from "node:fs"
import { readFile } from "node:fs/promises"
import { basename } from 'node:path'
import { WASI }  from "node:wasi"

const [,cliName, wasmFile] = process.argv

if (!wasmFile) {
  console.error(`Usage: ${basename(cliName)} <WASM_FILE>`)
  process.exit(1)
}

// this builds the unfettered WASI, but I will replace with my own
const wasi = new WASI({
  version: 'preview1',
  args: [],
  env: {}
})

const importObject = {
  wasi_snapshot_preview1: wasi.wasiImport,
  wasidev: {
    image_to_buffer(image_to_fd){},
    sound_to_buffer(sound_to_fd){}
  }
}

const wasm = await WebAssembly.compile(await readFile(wasmFile))
const instance = await WebAssembly.instantiate(wasm, importObject)

wasi.start(instance)


