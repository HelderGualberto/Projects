#include <iostream>
#include <math.h>

using namespace std;
#define min 1.0
#define max 2.0
#define alpha 0.0

int main(){

	double h = 0.1;
	double t = min;
	double w = alpha;
	double f = 0;

	for(int i = 1; i <= 11; i++){
		w = w + h*(2.0*w/t + t*t*exp(t));

		f = (t*t) * exp(t) - (t*t)*exp(1);

		t = min + i*h;

		cout << "w: " << w << " t: " << t << "real: " << f <<endl;
	}

}
