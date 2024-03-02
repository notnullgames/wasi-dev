import { WasmFs } from '@wasmer/wasmfs'
import { IoDevices } from '@wasmer/io-devices'

const wasmFs = new WasmFs()
const ioDevices = new IoDevices(wasmFs)

// todo: add this stuff https://medium.com/wasmer/wasmer-js-9a53e837b80

ioDevices.setBufferIndexDisplayCallback(() => {
  console.log(ioDevices.getFrameBuffer())
})

wasmFs.fs.writeFileSync('/_wasmer/dev/fb0/draw', '0')
