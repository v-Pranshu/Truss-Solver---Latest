#include <iostream>
#include <vector>
#include <math.h>

#include "mem.hpp"
#include "jo.hpp"
#include "supp.hpp"
#include "TrussSolve.hpp"


using namespace std;

Members member[numMembers];
Joints joint[numJoints];
Supports support[numSupports];
Forces force[numForces];

int main(){
    //set_jsInputs(joint, support, force);
    set_MemberInputs(member);
    set_jointInputs(joint);
    set_SupportForceInputs(support, force);

    for(int i = 0; i<numMembers; i++){
        double diffX = (joint[member[i].start_point].x_coord - joint[member[i].end_point].x_coord);
        double diffY = (joint[member[i].start_point].y_coord - joint[member[i].end_point].y_coord);
        double x1 = diffX*diffX;
        double y1 = diffY*diffY;

        member[i].length = sqrt(x1 + y1);
    }
    solveTruss(force, joint, support, member);
}

