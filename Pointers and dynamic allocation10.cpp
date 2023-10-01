#include<bits/stdc++.h>
using namespace std;
int main(){
	cout << "Tham Lap Phong 20215449: \n";
    int n;
    int **mt1, **mt2;
	cout <<"nhap n: \n";
    cin >> n;
	
    // Cap phat bo nho cho mt1, mt2
    mt1 = new int*[n];
    mt2 = new int*[n];
    for(int i=0; i<n; i++){
        mt1[i] = new int[n];
        mt2[i] = new int[n];
    }

    // Nhap gia tri cho mt1
    cout <<"Nhap gia tri mt1: \n";
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
        	cout <<"mt1["<<i<<"]"<<"["<<j<<"]"<<"= ";
			cin >> mt1[i][j];
        }
    // nhap gia tri mt2
    cout <<"Nhap gia tri mt2: \n";
	for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
        	cout <<"mt2["<<i<<"]"<<"["<<j<<"]"<<"= ";
            cin >> mt2[i][j];
        }
    // Tinh va in va tong cua 2 ma tran
    int tong =0;
    cout <<"tong 2 ma tran la: \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tong = mt1[i][j] + mt2[i][j];
            cout <<tong << " ";
        }
		cout << endl;
    }
	// Tinh va in ra tich cua 2 ma tran
	cout <<"Tich cua 2 ma tran la: \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
        	int tich =0;
            for(int k=0; k<n; k++){
                tich += mt1[i][k]*mt2[k][j];
            }
            		cout <<tich << " ";       
			}
	    cout << endl;
    }
}
