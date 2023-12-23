<h1>What is it?</h1>

<p>Elysian Engine is a basic exploration of 2D engine architecture in C++ and SDL2, intended for learning purposes. Currently the focus is on architecture and memory management, with only basic on-screen animated sprites and input implemented.</p>

<h2>Todo</h2>
<ul>
  <li>
  Implement command structure in UpdateState() to pass updates in a more orderly way
  <ul>
    <li>Implement CommandStream object with HashMap of Commands</li>
    <li>Refactor UpdateState loop to process commands</li>
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

