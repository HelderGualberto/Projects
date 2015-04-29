#include <ch.h>
#include <highgui.h>

using namespace cv;

int main(int argc,char**argv){
	char* imageName = argv[1];
	Mat image; 
	image = imread(imageName,1);

	if(argc != 2 || !image.data ){
		printf("No image data!\n");
		return -1;
	}

	Mat grayImage;
	ctvColor(image,grayImage,CV_BGR2GRAY);
	imwrite("result.jpg",grayImage);
	return 0;
}