#pragma once
#include "Inputs.hpp"


class Supports{
    public:
        int joint_index;
        int support_type;
        double x_dir = 0;
        double y_dir = 1;

        struct react{
            double x_comp = 0;
            double y_comp = 0;
        }reaction_force;

};

class Forces {
    public:
        double x;
        double y;
        struct force_comp{
            double x_comp;
            double y_comp;
            
        }components;
};

void set_SupportForceInputs(Supports support[numSupports], Forces force[numForces]);
