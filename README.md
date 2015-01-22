# Crawl

A dungeon crawler experiment

## Requirements

* SDL
* SDL_Image - jpg
* Google FlatBuffers - serialisation for save games & networking

We still need to decide on how to handle:

* networking (udp & tcp)
* distribution (steam, android, windows store...)
* copy protection

## Building

### Linux and OS X

run `qmake`

### Win

Not implemented - will follow standard qmake desktop build

### Android

Not implemented

### iOS

Not implemented - flatbuffers offers no `c` binding.