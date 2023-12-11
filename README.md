<h1>What is it?</h1>

<p>Elysian Engine is a basic exploration of 2D engine architecture in C++ and SDL2, intended for learning purposes. Currently the focus is on architecture and memory management, with only basic on-screen animated sprites and input implemented.</p>

<h2>Todo</h2>
<ul>
  <li>
  Improve memory management
  <ul>
    <li>Remove all naked pointers and replace with unique_ptr</li>
    <li>Implement copy/move semantics for GameObject / GameObjectComponent classes.</li>
  </ul>
  </li>
  <li>
  Implement collision detection
  <ul>
    <li>Simple AABB collision as a first step</li>
  </ul>
  </li>
    <li>Implement tilemap import</li>
    <li>Implement input wrapper</li>
</ul>

