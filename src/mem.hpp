#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include "Inputs.hpp"
using namespace std;


class Members{
    public:
        string material;    //Material to decide properties like Elasticity modulus etc,
        int start_point;    //joint index of starting point
        int end_point;      //joint index of end point

        int away_point;     //joint index of joint that is away from point where force balance equations are being written

        struct mem_force{
            double x = 0;
            double y = 0;
            double netForce = 69;
            bool done = false;
        }force;             // changing to struct//Force along the length of the member (+ -> extension, - -> compression)

        double length;      //Stores length of member (need to be calculated using joint class)
};



void set_MemberInputs(Members member[numMembers]);

