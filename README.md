# Truss-Solver

Currently solves trusses with two static supports that are fixed on the ground and face upwards, need to still incorporate more options for support.

## Way of Solving

Basically forms an AX = B type equation in each joint here X matrix comprises of unknown forces passing through the joint, A matrix is composed of the sines and cosines of these unknown forces and B matrix is composed of forces that are known. This system of equations is later solved using Gauss jordan elimination and back substitution.
