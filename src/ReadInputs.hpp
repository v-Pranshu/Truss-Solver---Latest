#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Inputs.hpp"
#include "jo.hpp"
#include "mem.hpp"
#include "supp.hpp"

using namespace std;

void getInputs(Members member[numMembers], Joints joint[numJoints], Supports support[numSupports]);