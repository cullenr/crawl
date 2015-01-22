# Design

## Concerns

* mobile platforms with limited memmory and the need to suspend the app at any moment.

## Architecture

* MVC pattern 
* No RTTI
* Configuration through dependancy injection

## Models

Models should be based off of FlatBuffers for 
* simple save game/ suspend serialisation
* limited to no accessors

## View

Prefer GL

## Controllers

Try to stick to namespaced free functions.

## Structure

**`main.cpp`**

Kick the gane off here, any dependancy injection happens manually here, typically we will have seperate `main` files per platform:
    
    src/
        main_linux_debian.cpp
        main_linux_fedora.cpp
        main_osx_10.8.cpp
        main_osx_10.9.cpp
        main_win.cpp
        main_win_metro.cpp

**`game.cpp`**

Game is the only statefull controller, it contains references to the other controllers used for a scene. This object will possibly exposed to a scripting engine for wiring at some point.


game

scene
