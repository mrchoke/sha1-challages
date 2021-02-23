# SHA1 chanllenges with Elixir

## Building

For running `sha1.exs`, you can run by elixir directly:

```shell
$ time elixir sha1.exs
```

But for `sha1_2.exs`, it requires `cmake` to building c code. Here is the build instructions:

```shell
$ mkdir build
$ cd build
$ cmake ..
$ make
$ cd ..
$ time elixir sha1_2.exs
```

If you're not using homebrew to install `erlang`. You can change erlang root by edit `CMakeLists.txt`:

```diff
diff --git a/elixir/thanabodee/CMakeLists.txt b/elixir/thanabodee/CMakeLists.txt
index 802c845..691decf 100644
--- a/elixir/thanabodee/CMakeLists.txt
+++ b/elixir/thanabodee/CMakeLists.txt
@@ -2,7 +2,7 @@ cmake_minimum_required(VERSION 3.19)
 project(encoding C)

 set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
-set(ERLANG_ROOT_DIR /usr/local/Cellar/erlang/23.2.5/lib/erlang)
+set(ERLANG_ROOT_DIR <your_erlang_root_dir>)
 include_directories(${ERLANG_ROOT_DIR}/usr/include/)
 add_library(encoding_nif SHARED encoding_nif.c)
 set_target_properties(encoding_nif
```

Change the `<your_erlang_root_dir>` to proper path.
