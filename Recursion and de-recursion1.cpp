#include <iostream>
using namespace std;
int lucas(int n) {
    if(n <=1 ) return 2 - n;
    return lucas(n-2) + lucas(n-1);
}
//Tham Lap Phong 20215449
int main (){
	int n;
	cin >> n;
	cout << lucas(n);	
	return 0;
}
