#include "jo.hpp"


void set_jointInputs(Joints joint[numJoints]){
    joint[0].x_coord = 0;
    joint[0].y_coord = 0;
    joint[0].isSupport = true;
    joint[0].supInd = 0;

    joint[1].x_coord = 2;
    joint[1].y_coord = 0;
    joint[1].isSupport = false;

    joint[2].x_coord = 4;
    joint[2].y_coord = 0;
    joint[2].isSupport = true;
    joint[2].supInd = 1;

    joint[3].x_coord = 1;
    joint[3].y_coord = 1;
    joint[3].isSupport = false;

    joint[4].x_coord = 3;
    joint[4].y_coord = 1;
    joint[4].isSupport = false;

    joint[5].x_coord = 2;
    joint[5].y_coord = 2;
    joint[5].isSupport = false;
}