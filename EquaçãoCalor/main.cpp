#include <iostream>
#include <math.h>
using namespace std;
#define alpha 1

int main()
{

    double h = 0.01;
    double k = 0.0005;
    double lambda = alpha*alpha*k/(h*h);
    int n = 1/0.0005;
    double *w = new double[10];

    int i;
    for(i=0;i<10;i++){
        w[i] = sin(3.1416*i*h);
    }

    double *l = new double[10];
    double *u = new double[10];

    l[0] = 1+2*lambda;
    u[0] = lambda/l[0]*(-1);

    for(i=1;i<=8;i++){
        l[i] = 1+2*lambda+lambda*u[i-1];
        u[i] = lambda/l[0]*(-1);
    }
    l[9] = 1+2*lambda+lambda*u[8];

    int j;
    double *z = new double[10];

    z[0]=w[0]/l[0];

    for(i=1;i <= 9;i++){
        z[i] = (w[i]+lambda*z[i-1])/l[i];
    }
    w[9] = z[9];
    for(i=1;i < 9;i++){
        w[i]=z[i]-u[i]*w[i+1];
        cout << w[i] << endl;
    }

    return 0;
}
