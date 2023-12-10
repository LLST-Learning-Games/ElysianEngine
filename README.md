What is it?

Elysian Engine is a basic exploration of 2D engine architecture in C++ and SDL2, intended for learning purposes. Currently the focus is on architecture and memory management, with only basic on-screen animated sprites and input implemented.

Todo
-Improve memory management
  -Remove all naked pointers and replace with unique_ptr
  -Implement copy/move semantics for GameObject / GameObjectComponent classes.
-Implement collision detection
  -Simple AABB collision as a first step
-Implement tilemap import
-Implement input wrapper 

