#include "ReadInputs.hpp"
#include <string.h>

void getInputs(Members member[numMembers], Joints joint[numJoints], Supports support[numSupports]) {
    ifstream inFile;
    inFile.open("Geometry.txt");

    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    string line;
    string comm = "//+";
    int jointIndex, memIndex = 0;
    int joints_read = 0;
    int members_read = 0;

    cout << "READING INPUTS #" << endl;

    while(getline(inFile , line)){

        //cout << "#" << endl;
        int lineCount = line.size();

        //cout << line << endl;

        if(line.compare(comm) == 0){
            //cout << line << endl;
            continue;
        }

        else if(joints_read < numJoints && line[0] != '/' ){
            for (int i = 0; i<lineCount; i++){
                if(line[i] == '('){
                    jointIndex = line[i+1] - '1';
                    joint[jointIndex].isSupport = false;
                    //cout << "Joint read: " << line <<endl;
                }

                else if(line[i] == '{'){
                    joint[jointIndex].x_coord = line[i+1] - '0';
                    joint[jointIndex].y_coord = line[i+4] - '0';   
                }

                

                //cout << "i: " << line[i] << endl;
            }

            joints_read++;
            //cout << "joints_read: " << joints_read << endl;

        }

        else if (members_read < numMembers && line[0] != '/'){
            for (int i = 0; i<lineCount; i++){
                if(line[i] == '('){
                    memIndex = line[i+1] - '1';
                    //cout << "Member read: " << line <<endl;
                }

                else if(line[i] == '{'){
                    member[memIndex].start_point = line[i+1] - '1';
                    member[memIndex].end_point = line[i+4] - '1'; 
                    //cout << "Member start: " << member[memIndex].start_point <<endl;
                }
            }
            members_read ++;
            //cout << "numMmbers read: "<< members_read << endl;
        }  

        else{

            int ind[2];
            for (int i = 0; i<lineCount; i++){
                if(line[i] == '{'){
                    ind[0] = line[i+1] - '1';
                    ind[1] = line[i+4] - '1';
                    joint[ind[0]].isSupport = true;
                    joint[ind[0]].supInd = 0;

                    joint[ind[1]].isSupport = true;
                    joint[ind[1]].supInd = 1;

                    support[0].joint_index = ind[0];
                    support[1].joint_index = ind[1];
                }         
            }
        }
    }
}