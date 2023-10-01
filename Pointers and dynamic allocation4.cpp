#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
int counteven(int* arr, int size){
    int count = 0;
     //Ham tr? v? s? lu?ng s? ch?n trong m?ng 
    for(int i = 0; i < size; i++){
        if(arr[i]%2==0) count++; //n?u arr[i] là s? ch?n thì d?m +1
    }
    
    return count;    
}
int main(){
	int arr[]= {1,5,4,8,10,6,7,2};
	cout <<"Output 1: " << counteven(arr,8) <<"\n";
	int arr1[] = {1, 5, 4, 0, 10, 7};
	cout <<"Output 2: " << counteven(arr1, 6);	
	return 0;
}
