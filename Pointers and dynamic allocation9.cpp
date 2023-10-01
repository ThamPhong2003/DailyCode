#include<bits/stdc++.h>
using namespace std;
int main(){
    cout << "Tham Lap Phong 20215449" << "\n";
	int n;
    // Nhap day
    cout << "so phan tu cua day la: \n";
    cin >> n;
    cout <<"Cac phan tu trong day lan luot la: \n";
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    // in ra cac day con
    cout << "Cac day con la:\n";
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++){
            for(int k=i; k<=j; k++)
            cout << arr[k] << " ";
            cout << endl;
        }
    return 0;
}
