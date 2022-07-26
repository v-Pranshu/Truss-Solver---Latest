
#include "mem.hpp"
#include "jo.hpp"
#include "supp.hpp"

void calculateReactions(Forces force[numForces], Joints joint[numJoints], Supports support[numSupports]);
void member_forces(Joints joint[numJoints], Supports support[numSupports], Members member[numMembers], Forces force[numForces],  int j, vector <int> deter, vector <int> undeter);
void solveTruss(Forces force[numForces], Joints joint[numJoints], Supports support[numSupports], Members member[numMembers]);
void gauss_jordan(double A[nDim][nDim], double B[nDim][1], double F[nDim][1]);
