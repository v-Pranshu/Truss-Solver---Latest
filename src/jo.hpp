#include "mem.hpp"

class Joints{
    public:
        double x_coord; 
        double y_coord;

        bool isSupport;
        int supInd;
};

void set_jointInputs(Joints joint[numJoints]);