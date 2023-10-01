#include<bits/stdc++.h>
using namespace std;

void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp;
    
    while(l < r){
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++;
        r--;
    }
}

void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, tmp;
    int *p;
    p = arr;
    while(l < r){
        tmp = *(p+l);
        *(p+l) = *(p+r);
        *(p+r) = tmp;
        l++;
        r--;
    }
    
}
int main (){
	cout <<"Tham Lap Phong 20215449";
	cout << "\n";
	// input1	
	int arr[] = {9, 3, 5, 6, 2, 5};
	reversearray(arr, 6);
	for(int i = 0; i < 6; i++) cout << arr[i] << " ";
	int arr2[] = {4, -1, 5, 9};
	ptr_reversearray(arr2, 4);
	for(int i = 0; i < 4; i++) cout << arr2[i] << " ";
	cout <<"\n";
	// Input 2
	int arr3[] = {9, 6, 2, 5};
	reversearray(arr3, 4);
	for(int i = 0; i < 4; i++) cout << arr3[i] << " ";
	int arr4[] = {12, 4, -1, 5, 9};
	ptr_reversearray(arr4, 5);
	for(int i = 0; i < 5; i++) cout << arr4[i] << " ";
}

