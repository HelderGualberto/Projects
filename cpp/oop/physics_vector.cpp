#include "physics_vector.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

//Constructor that generate random data for the vector
PhysicsVector::PhysicsVector(int size){
    this->size = size;
    this->points = generate_random_data();
    this->calc_module();
}

//Constructor that uses the data given
PhysicsVector::PhysicsVector(int size, vector<float> points){
    this->size = size;
    this->points = points;
    this->calc_module();
}

// DESTRUCTOR
PhysicsVector::~PhysicsVector(){
    //Free memory from pointers
    //delete this->module;
}

void PhysicsVector::calc_module(){
    float *aux = new float;
    for(int i=0;i<this->size;i++){
        (*aux)+=pow(this->points[i],2);
    }
    *aux = sqrt((*aux));
    this->module = aux;
}

void PhysicsVector::print_points(){
    cout << "Points: ";
    for(int i=0;i<this->size;i++){
        cout << this->points[i] << " ";
    }
    cout << endl;
}

vector<float> PhysicsVector::generate_random_data(){
    vector<float> random_data;

    for(int i=0;i<this->size;i++){
        random_data.push_back((float)((rand() % 10000 - 5000))/5000.0);
    }

    return random_data;
}

float calc_inner_product(vector<float> v1, vector<float> v2){
    float aux=0;
    for(int i=0;i<v1.size();i++){
        aux += v1[i] * v2[i];
    }
    return aux;
}

float PhysicsVector::calc_angle(PhysicsVector v1, PhysicsVector v2){
    float prod = calc_inner_product(v1.points,v2.points);
    float aux = v1.module[0] * v2.module[0];
    return acos(prod/aux)*(180/3.1416);
}

//Not a simple vectorial space distance, but a complete object distance, including module
//OBS: Physics_vector MUST be the same size (number of dimensions)
float PhysicsVector::calc_dist(PhysicsVector v1, PhysicsVector v2){
    float aux=0;
    //Calc distance for points
    for(int i=0;i<v1.size;i++){
        aux+=pow((v1.points[i]-v2.points[i]),2);
    } 

    aux+=pow((v1.module[0]-v2.module[0]),2);

    return sqrt(aux);
}