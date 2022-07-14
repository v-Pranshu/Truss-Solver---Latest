#include "mem.hpp"

void set_MemberInputs(Members member[numMembers]){
    member[0].start_point = 0;
    member[0].end_point = 1; //
    member[0].length = 1;

    member[1].start_point = 1; //
    member[1].end_point = 2;
    member[1].length = 1;

    member[2].start_point = 1;
    member[2].end_point = 3;
    member[2].length = 1;

    member[3].start_point = 1; //
    member[3].end_point = 4;
    member[3].length = 1;

    member[4].start_point = 1; //
    member[4].end_point = 5;
    member[4].length = 1;

    member[5].start_point = 0;
    member[5].end_point = 3;
    member[5].length = 1;

    member[6].start_point = 3;
    member[6].end_point = 5;
    member[6].length = 1;

    member[7].start_point = 2;
    member[7].end_point = 4;
    member[7].length = 1;

    member[8].start_point = 4;
    member[8].end_point = 5;
    member[8].length = 1;

}