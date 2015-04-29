#include <stdio.h>
#include <iostream>
#include <opencv.hpp>
#include <fstream>

using namespace cv;
using namespace std;

void drawPoints(Mat *img,int x,int y){
	line(*img,Point(x,y),Point(x,y),Scalar(255,0,0),2,8);
}

double exp(double x,int e){
	double aux = x;
	for (int i = 1; i < e; i++){
		x*=aux;
	}
	return x;
}

int main(){
	double *x;
	double *a,*h,*b,*c,*d,*u,*z,*y,*l;
	int n;
	
	cout << "Insert the number of points" << endl;

	cin >> n;

	x = new double[n];
	a = new double[n];
	b = new double[n];
	c = new double[n];
	d = new double[n];
	h = new double[n];
	u = new double[n];
	z = new double[n];
	y = new double[n];
	l = new double[n];


	FILE* file;
	file = fopen("C:\\Users\\Helder\\Documents\\GitHub\\Projects\\SplineCubico\\x.txt","r");

//	cout << "Insert X values and press enter" <<endl;

	for(int i = 0;i < n;i ++){
		fscanf(file,"%lf",&x[i]);
	}
	fclose(file);

	file = fopen("C:\\Users\\Helder\\Documents\\GitHub\\Projects\\SplineCubico\\fx.txt","r");

	for(int i = 0;i < n;i ++){
		fscanf(file,"%lf",&a[i]);
	}
	fclose(file);
	n--;

	for(int i = 0;i < n;i++){
		h[i]=x[i+1]-x[i];
	}
	for(int i = 1;i < n;i++){
		y[i] = (3/h[i])*(a[i+1]-a[i]) - (3/h[i-1])*(a[i]-a[i-1]);
	}

	l[0]=1;u[0]=0;z[0]=0;

	for(int i=1;i<n;i++){
		l[i] = 2*(x[i+1]-x[i-1])-(h[i-1]*u[i-1]);
		u[i] = h[i]/l[i];
		z[i] = (y[i]-h[i-1]*z[i-1])/l[i];
	}

	l[n]=1;z[n]=0;c[n]=0;

	for(int j=n-1;j >=0;j--){
		c[j]=z[j]-u[j]*c[j+1];
		b[j]=(a[j+1]-a[j])/h[j] - h[j]*(c[j+1]+2*c[j])/3;
		d[j]=(c[j+1]-c[j])/(3*h[j]);
	}

	for(int i = 0;i < n;i++){
		cout << "a" << i << "="<< a[i] << " b" << i << "="<< b[i] 
		<< " c" << i << "="<< c[i] << " d" << i << "="<< d[i] <<endl;
	}


	Mat img = Mat::zeros(600,600,CV_8UC3);
	double x1;int j = 0, k = 0;
	float f;
	
	for(int i=0;i < n;i ++){

		f = a[k] + b[k]*x1 + c[k]*exp(x1,2) + d[k]*exp(x1,3);

		drawPoints(&img,i,500 - f);
	}
	imshow("teste",img);
	waitKey(0);
	

	/*for(int i = 0; i< n; i++){
		cout << a[i] << " ";
	}
	*/
	

	system ("PAUSE");
	return 0;
}
