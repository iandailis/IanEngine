# IanEngine
3D engine running on Vulkan and packaged/installed by CMake.

To install:
1. Go to IanEngine-lib
2. Make a build directory, then go inside of it.
3. Run "cmake .." then "make install"

To run:
1. Go to IanEngine-run
2. Make a build directory, then go inside of it.
3. Run "cmake .." then "make"
4. Add the library location to PATH. The install location is printed right before all the files are installed, during step 3 of installation.
5. Run the program. 

Currently, this is what you can do:

* W/S : Move camera along the Y axis
* A/D : Move camera along the X axis
* Q/E : Move camera along the Z axis
* Z/X/C : Rotate camera around the Z/X/Y axis
* PG_DN/PG_UP : Zoom camera out/in
* +/- : Select object to move
* I/K J/L U/O : Moves selected object with same control mapping as for camera movement
* F/G/H : Rotates selected object around its X/Y/Z axis. These axes are parallel to the coordinate axis. 
* Space (Hold) : snakey snake snake

You can generate the following objects:
* Right Triangle
* Rectangle
* Cube
* Cylinder

Enjoy!
