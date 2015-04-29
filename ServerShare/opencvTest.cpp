#include <opencv2\opencv.hpp>


int main (int argv,char **argc){

if(argv < 1){
	printf("Insert the file path!\n");
	return -1;
}
	//VideoCapture cap;
	//cap.open(1);

	Mat frame;
	
	for(;;){
		frame = imread(argc[argv]);
		imshow("asdasd",frame);
	//	change_RGB(&frame);
	//	imshow("Ad",frame);
		waitKey(12);
	}

	return 0;	
}

cmake_minimum_required(VERSION 2.8)
project( teste )
find_package( OpenCV REQUIRED )
add_executable( DisplayImage teste.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )