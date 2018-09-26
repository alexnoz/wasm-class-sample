#!/usr/bin/env bash

url="http://localhost:8080"

# Ideally, `js` and `wasm` files should be emitted to some build folder,
# but it doesn't work ¯\_(ツ)_/¯

emcc --bind -Oz dog.cc -o dog.js \
-s WASM=1 -s NO_EXIT_RUNTIME=1 -s "EXTRA_EXPORTED_RUNTIME_METHODS=['addOnPostRun']" \
|| exit 1

case "$OSTYPE" in
  msys)
    start $url;;
  cygwin)
    cygstart $url;;
  darwin*)
    open $url;;
  *)
    xdg-open $url;;
esac
