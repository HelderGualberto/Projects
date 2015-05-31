//
//  holt-winter.c
//  Holt-Winter
//
//  Created by Joao Sisanoski on 5/18/15.
//  Copyright (c) 2015 Joao Sisanoski. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

void imprimir(double *array, int tamanho){
			std::ofstream myfile;
			myfile.open("d://teste.txt");
    for(int x = 0 ; x < tamanho; x++){
		myfile << array[x] << endl;
        printf("%d  -  %f\n",x,array[x]);
		
	}
			myfile.close();

}

double media(double *array, int tamanho){
    double y = 0;
    for(int x = 0 ; x < tamanho; x++){
        y+=array[x];
    }
    return y/(double)tamanho;
}
double *seasonalFactorYear1(double *array, int tamanho){
    double *seasonal = (double*)malloc(tamanho*sizeof(double));
    double ave = media(array, tamanho);
    for(int x = 0 ; x < tamanho; x++){
        seasonal[x]= array[x]-ave;
    }
    return seasonal;
}
void  copiaValor(double*array1, double *array2, int tamanho){
    for (int x = 0 ;  x < tamanho; x++) {
        array2[x]= array1[x];
    }
}
double *forecasting_holt_winter(double *ano1, int tamanho1, double *ano2, int tamanho2, double alpha, double beta, double gama, int timeToForecast){
    double *seasonalFactor = seasonalFactorYear1(ano1, tamanho1);
    double *seasonalFactorAll = (double*)malloc(sizeof(double)*(tamanho1+tamanho2));
    copiaValor(seasonalFactor, seasonalFactorAll, tamanho1);
    
    free(seasonalFactor);
    
    double *baseLevel = (double*)malloc((tamanho2+1)*sizeof(double));
    baseLevel[0]= ano1[tamanho1-1]-seasonalFactorAll[tamanho1-1];
    
    double *trend = (double*)malloc((tamanho2+1)*sizeof(double));
    double *forecast = (double*)malloc((sizeof(double)*timeToForecast));
    trend[0]=0;
    for(int x= 0 ; x < tamanho2 ; x++){
        baseLevel[x+1] = alpha*(ano2[x]-seasonalFactorAll[x])+(1-alpha)*(baseLevel[x]+trend[x]);
        trend[x+1]= beta*(baseLevel[x+1]-baseLevel[x])+(1-beta)*trend[x];
        seasonalFactorAll[tamanho1+x]= gama*(ano2[x]-baseLevel[x+1])+(1-gama)*(seasonalFactorAll[x]);
    }
    for (int x = 0 ; x < timeToForecast; x++) {
        forecast[x]= baseLevel[tamanho2]+trend[tamanho2]*(x+1)+seasonalFactorAll[tamanho2+x];
    }
    free(seasonalFactorAll);
    free(trend);
    free(baseLevel);
    
    return forecast;
}

int main(int argc, const char * argv[]) {
    double ano1[30] = {
183,
121,
143,
175,
121,
137,
163,
123,
182,
164,
182,
149,
185,
127,
149,
167,
127,
133,
153,
127,
178,
156,
192,
146,
177,
127,
157,
169,
117,
128
};
    double ano2[1] = {152};
    double *x=  forecasting_holt_winter(ano1, 30, ano2, 1, 0.3, 0.2, 0.1, 29);
    imprimir(x, 29);

	system("pause");
    return EXIT_SUCCESS;
}
