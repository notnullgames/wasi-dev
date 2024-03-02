This contains 2 hosts for running wasi-dev wasm apps.

- web - a web-based host runtime
- native - an glfw/miniaudio host host runtime, using WAMR
- node - I use this to prototype the host, in nodejs


## host interface

A host should implement these from WASI preview1:

```
wasi_snapshot_preview1:
  args_get(i32, i32) -> i32
  args_sizes_get() -> i32
  clock_res_get(i32) -> i32
  clock_time_get(i32, i32) -> i32
  environ_get(i32, i32) -> i32
  environ_sizes_get() -> i32
  fd_advise(i32, i32, i32, i32) -> i32
  fd_allocate(i32, i32, i32) -> i32
  fd_close(i32) -> i32
  fd_datasync(i32) -> i32
  fd_fdstat_get(i32, i32) -> i32
  fd_fdstat_set_flags(i32, i32) -> i32
  fd_fdstat_set_rights(i32, i32, i32) -> i32
  fd_filestat_get(i32) -> i32
  fd_filestat_set_size(i32, i32) -> i32
  fd_filestat_set_times(i32, i32, i32, i32) -> i32
  fd_pread(i32, i32, i32) -> i32
  fd_prestat_get(i32) -> i32
  fd_prestat_dir_name(i32, i32, i32) -> i32
  fd_pwrite(i32, i32, i32) -> i32
  fd_read(i32, i32) -> i32
  fd_readdir(i32, i32, i32, i32) -> i32
  fd_renumber(i32, i32) -> i32
  fd_seek(i32, i64, i32, i32) -> i32
  fd_sync(i32) -> i32
  fd_tell(i32) -> i32
  fd_write(i32, i32, i32, i32) -> i32
  path_create_directory(i32, i32) -> i32
  path_filestat_get(i32, i32, i32) -> i32
  path_filestat_set_times(i32, i32, i32, i32, i32, i32) -> i32
  path_link(i32, i32, i32, i32, i32) -> i32
  path_open(i32, i32, i32, i32, i32, i32, i32) -> i32
  path_readlink(i32, i32, i32, i32) -> i32
  path_remove_directory(i32, i32) -> i32
  path_rename(i32, i32, i32, i32) -> i32
  path_symlink(i32, i32, i32) -> i32
  path_unlink_file(i32, i32) -> i32
  proc_exit(i32) -> nil
  proc_raise(i32) -> i32
  random_get(i32, i32) -> i32
```

these utils will load parsed files into file-like buffers:

```
wasidev:
  image_to_fd(i32) -> i32
  sound_to_fd(i32) -> i32
  http_get_to_fd(i32) -> i32
```

Some WASI functions were not implemented, but feel free to make them yourself:

```
wasi_snapshot_preview1:
  poll_oneoff(i32, i32, i32) -> i32
  sched_yield() -> i32
  sock_accept(i32, i32) -> i32
  sock_recv(i32, i32, i32) -> i32
  sock_send(i32, i32, i32) -> i32
  sock_shutdown(i32, i32) -> i32
```

## NOTES

- setup [minizip](https://github.com/zlib-ng/minizip-ng) for operating on parent zip file
- add [asyncify](https://www.npmjs.com/package/asyncify-wasm)
