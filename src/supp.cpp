
#include "supp.hpp"


void set_SupportForceInputs(Supports support[numSupports], Forces force[numForces]){
    
    force[0].x = 2;
    force[0].y = 2;
    force[0].components.x_comp = 0;
    force[0].components.y_comp = -75;

    force[1].x = 3;
    force[1].y = 1;
    force[1].components.x_comp = 0;
    force[1].components.y_comp = -50;

    support[0].joint_index = 0;
    support[1].joint_index = 2;

}
