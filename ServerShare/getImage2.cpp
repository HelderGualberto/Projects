#include <opencv2/opencv.hpp>

int main (){

	CvCapture * capture = cvCaptureFromCAM(0);

	IplImage* image;
	
	image = cvQueryFrame(capture);
	
	cvSaveImage("~/teste.jpg",image);
	waitKey(10);
	
	return 0;	
}