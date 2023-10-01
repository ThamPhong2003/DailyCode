#include <bits/stdc++.h>
using namespace std;
double* maximum(double* a, int size){
    double *max;
    max = a;
    if (a==NULL) return NULL;

    for(int i = 0; i < size;i++){
        if(a[i] > *max) *max = a[i];
        //gán pt l?n hon *max vào *max
    }
    
    return max;
}

int main(){
	cout <<"Tham Lap Phong 20215449 \n";
	//input 1
	double arr[] ={1,10,2,-7,25,3};
	cout << "Output 1: ";
	cout << *maximum(arr,6);
	cout <<"\n";
	//input 2
	cout <<"Output 2: ";
	double* arr3 = NULL;
	double* max2 = maximum(arr3, 6);
	printf("%.d \n", max2==NULL?1:0);
	//input 3
	double arr2[] = {12.};
	double* max1 = maximum(arr2, 1);
	cout << "Output 3: ";
	printf("%.0f", *max1);
	return 0;
}
