#include "TrussSolve.hpp"



// For now calculates only orthogonal reactions for a single external force applied on the truss
void calculateReactions(Forces force[numForces], Joints joint[numJoints], Supports support[numSupports]){

    double netExtForce;

    for(int i = 0; i<numForces; i++){

        support[1].reaction_force.y_comp += -force[i].components.y_comp*(force[i].x - joint[support[0].joint_index].x_coord)/(joint[support[1].joint_index].x_coord - joint[support[0].joint_index].x_coord);

        netExtForce += force[i].components.y_comp;
    }

    support[0].reaction_force.y_comp = -netExtForce - support[1].reaction_force.y_comp;

}

void member_forces(Joints joint[numJoints], Supports support[numSupports], Members member[numMembers], Forces force[numForces],  int j, vector <int> deter, vector <int> undeter){      //j = index of joint at which forces are to be calculated

    //Calculate forces of members passing through joint with 1st support

    double B[2][1] = {{0}, {0}};
    double A[2][2];
    double F[2][1] = {{0}, {0}};

    if(joint[j].isSupport){
        B[0][0] = -support[joint[j].supInd].reaction_force.x_comp;
        B[1][0] = -support[joint[j].supInd].reaction_force.y_comp;
    }


    else{

        for(int i = 0; i < numForces; i++){
            if(force[i].x == joint[j].x_coord && force[i].y == joint[j].y_coord){
                B[0][0] += -(force[i].components.x_comp);
                B[1][0] += -(force[i].components.y_comp);
            }
        }

        for(int i = 0; i < deter.size(); i++){
            B[0][0] += -(member[deter[i]].force.x);
            B[1][0] += -(member[deter[i]].force.y);

        }
    }



    for(int i = 0; i<undeter.size(); i++){

        if (member[undeter[i]].end_point != j){
            member[undeter[i]].away_point = member[undeter[i]].end_point;

        }

        else{
            member[undeter[i]].away_point = member[undeter[i]].start_point;
        }

        A[0][i] += (joint[member[undeter[i]].away_point].x_coord - joint[j].x_coord)/(member[undeter[i]].length);
        A[1][i] += (joint[member[undeter[i]].away_point].y_coord - joint[j].y_coord)/(member[undeter[i]].length);

    }

    gauss_jordan(A, B, F);

    for(int i = 0; i<undeter.size(); i++){
        member[undeter[i]].force.x = F[i][0]*A[0][i];
        member[undeter[i]].force.netForce = F[i][0];
        member[undeter[i]].force.y = F[i][0]*A[1][i];
        member[undeter[i]].force.done = true;
    }   
}

void solveTruss(Forces force[numForces], Joints joint[numJoints], Supports support[numSupports], Members member[numMembers]){
    
    //Calculate reaction forces by the support

    calculateReactions(force, joint, support);

    cout << endl;
    cout << "Reaction Force 2: " << support[1].reaction_force.y_comp << "N" << endl;
    cout << "Reaction Force 1: " << support[0].reaction_force.y_comp << "N" << endl;

    vector <int> jointSolved;
    vector <int> jointToBe_Solved;

    for(int i = 0; i<numJoints; i++){
        jointToBe_Solved.push_back(i);
    }

    int T = 0;
    //while(jointToBe_Solved.size() != 0){

        for(int j = 0; j<jointToBe_Solved.size(); j++){

            vector <int> Member_ind;        //Indices of members passing through joint
            vector <int> deter;             // Vector to store indices of members that pass through joint no. j whose forces have been determined
            vector <int> undeter;

            //On Given joint number check index of members passing through
            for (int i = 0; i<numMembers; i++){
                if (member[i].start_point == j || member[i].end_point == j){
                    Member_ind.push_back(i);
                }
            }

            //Initially member.forces = 69.0 (for all members for which forces have not yet been determined)

            for (int i = 0; i<Member_ind.size(); i++){
                if(member[Member_ind[i]].force.netForce == 69){
                    undeter.push_back(Member_ind[i]);
                }

                else{
                    deter.push_back(Member_ind[i]);
                }
            }


            if(undeter.size() == 2){
                member_forces(joint, support, member, force, j, deter, undeter);
                jointSolved.push_back(j);
                //jointToBe_Solved.erase(jointToBe_Solved.begin() + j);
            }

            else if (undeter.size() == 1){

                for(int i = 0; i<deter.size(); i++){
                    member[undeter[0]].force.x += member[deter[i]].force.x;
                    member[undeter[0]].force.y += member[deter[i]].force.x;
                } 

                double a1 = member[undeter[0]].force.x*member[undeter[0]].force.x;
                double b1 = member[undeter[0]].force.y*member[undeter[0]].force.y;

                member[undeter[0]].force.netForce = sqrt(a1+b1);
                jointSolved.push_back(j);
                //jointToBe_Solved.erase(jointToBe_Solved.begin() + j);

            }

            else if (undeter.size() == 0){

                jointSolved.push_back(j);
                //ointToBe_Solved.erase(jointToBe_Solved.begin() + j);
            }

            else{
                continue;
            }
        }

        //T ++ ;   
   // }

    if (T == 100){
        cout << "ERROR";
    }

    for(int i = 0; i<numMembers; i++){
        cout << "member " << i <<  " : " << member[i].force.netForce << "N" << endl;
    }
}

void gauss_jordan(double A[nDim][nDim], double B[nDim][1], double F[nDim][1]){
    
    //combine matrices
    double C[nDim][nDim+1];

    for(int i = 0; i<nDim; i++ ){
        for(int j = 0; j<nDim+1; j++){
            if(j!=nDim){
                C[i][j] = A[i][j];
            }

            else{
                C[i][j] = B[i][0];
            }
        }
    }

    int diag_index = 0;
    int cRow = 0;
    int cCol = 0;
    int rowIndex = 0;
    double rowOneval = 0;
    double cElement = 0;
    double factor;

    while(diag_index < nDim){
        cRow = diag_index;
        cCol = diag_index;

        rowIndex = cRow + 1;

        //If matrix is already in row echelon form then skip loop
        if (C[1][0] == 0){
            break;
        }

        while(rowIndex < nDim){
            rowOneval = C[cCol][cCol];
            cElement = C[rowIndex][cCol];

            factor = cElement/rowOneval;

            for(int i = 0; i < nDim+ 1; i++){
                C[rowIndex][i] = C[rowIndex][i] -factor*C[cRow][i];
            }

            rowIndex++;

        }

        diag_index++;
    }

    //After converting it to an REF form through Gauss jordan elimination
    //Perform Back Substitution to find force matrix
    F[1][0] =  C[1][2]/C[1][1];
    double a = (C[0][2]/C[0][0]);
    double b = C[1][2]/C[1][1];
    double c = C[0][1]/C[0][0];
    F[0][0] = a-(F[1][0]*c);
    
    
}
