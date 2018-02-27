#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
	int i;
	int a=0;
	int tid,n=0;
	clock_t start = clock();
	
	if(argc > 1){
		n = atoi(argv[1]);
		printf("input: %d\n",n);
	}
	else{
		printf("No input, ERROR\n");
		exit(EXIT_FAILURE);
	}

	

	//#pragma omp parallel for shared(a) 
	for(i=0;i < n;i++){
	//	#pragma omp critical
		a = a + 1;
		//tid = omp_get_thread_num();
		//printf("Hello from thread n = %d\n",tid);	
		
	}
	
	clock_t end = clock();
	float sec = (float)(end-start)/CLOCKS_PER_SEC;
	printf("result: %d\nTime: %f\n",a,sec);
	return 0;
}
