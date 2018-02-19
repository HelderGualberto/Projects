#include <iostream>
#include "physics_vector.hpp"
#include <vector>
#include <stdlib.h>

using namespace std;

int main(int argv, char* argc[]){


    if(argv < 2){
        cout << "Invalid args! Usage: <Number of vectors> <Dimensions>" << endl;
        return 0;
    }

    int num_vectors = atoi(argc[1]);
    int dim =  atoi(argc[2]);

    /*
    //Constructor for a non pointer variable
    PhysicsVector force(20);
    PhysicsVector force2(20);
    //Constructor for a poiter variable
    //PhysicsVector force = new PhysicsVector(3);

    cout << "Force 1" << endl;
    cout << "Dimentions: " << force.size << endl;
    force.print_points();
    cout << "Module: " << force.module[0] << endl;


    cout << "Force 2" << endl;
    cout << "Dimentions: " << force2.size << endl;
    force2.print_points();
    cout << "Module: " << force2.module[0] << endl;

    float dist = PhysicsVector::calc_dist(force, force2);
    cout << "Distance: " << dist << endl;


    float angle = PhysicsVector::calc_angle(force, force2);
    cout << "Angle: " << angle << endl;
    */
    float dist=0.0;
    float angle=0.0;

    #pragma omp_parallel_for
    for(int i=0;i<num_vectors;i++){
        PhysicsVector force(dim);
        PhysicsVector force2(dim);
        dist += PhysicsVector::calc_dist(force, force2);
        angle += PhysicsVector::calc_angle(force, force2);
    }

        cout << "Dist avg: " << dist/num_vectors << endl;
        cout << "Angle avg: " << angle/num_vectors << endl;

    return 0;
}