
/*
    Physics vector is a class that define a representation of an n dimensional physical vector.

    Attributes:
        - number of size - int
        - vector points - float*
        - angle - float
        - module - float
    
    Methods
        - calculate angle
        - calculate module
        - calculate distance
*/

#ifndef PHYSICS_VECTOR_H
#define PHYSICS_VECTOR_H

#include <iostream>
#include <vector>

class PhysicsVector{

    public:
        /* CONSTRUCTORS */

        //Create random data for the vector
        PhysicsVector(int size);
        
        //Use the data given
        PhysicsVector(int size, std::vector<float> points);

        // DESTRUCTOR
        ~PhysicsVector();

        //Calculate vector distance
        static float calc_dist(PhysicsVector v1, PhysicsVector v2);
        static float calc_angle(PhysicsVector v1, PhysicsVector v2);
        void print_points();
        

        std::vector<float> points;
        int size;
        float* module;

    private:
        void calc_module();
        std::vector<float> generate_random_data();

};



#endif 