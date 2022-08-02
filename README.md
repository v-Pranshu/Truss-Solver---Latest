# Truss-Solver

Currently solves trusses with two static supports that are fixed on the ground and face upwards, need to still incorporate more options for support.

## Way of Solving

Basically forms an AX = B type equation for each joint of the truss, here 'X' matrix comprises of unknown forces passing through the joint, 'A' matrix is composed of the sines and cosines of these unknown forces and 'B' matrix is composed of forces that are known. This system of equations is later solved using Gauss jordan elimination and back substitution.

## To Use
 1. Download the zipped repo
 2. Extract the repo and cd to extracted location in terminal
 3. Save your .geo file in the src directory.
 3. Type 'make' to compile the program
 4. Type './SolveTruss' to run the program
  
 ## Updates
 -> You can now give inputs to the solver through a .geo file, that will be generated through GMSH software. This means you can basically draw the geometry in GMSH by       placing points to represent joints, and lines that will represent the members. 
 
GMSH Page link that contains documentation and download links: https://gmsh.info/

 ## Additional features of post-processing will be added soon
