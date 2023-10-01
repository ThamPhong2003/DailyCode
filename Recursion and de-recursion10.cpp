#include<iostream>
// Tham lap Phong 20215449
using namespace std;
int A[17]={};
static int dem=0;
void print(int n){
    for(int i=1;i<=n;i++){
        cout<<A[i];
    }
    cout<<endl;
}
bool isCandidate(int k,int n,int x,int h){
    if(x==0){
        if(h-dem<=n-k) return true;
        else return false;
    }
    if(x==1){
        if(h>dem) return true;
        else return false;
    }
    return true;
}
void Try(int k,int n,int h){
    for(int i=0;i<=1;i++){
        int temp=dem;
        if (isCandidate(k,n,i,h)) A[k]=i;
        else continue;
        if(i==1) dem++;
        if(k==n) print(n);
        else Try(k+1,n,h);
        dem=temp;
    }
}
int main(){
    int Numcase;
    cin>>Numcase;
    int n[Numcase],h[Numcase];
    for (int i=0;i<Numcase;i++) {cin>>n[i];cin>>h[i];}
    for (int i=0;i<Numcase;i++){Try(1,n[i],h[i]);cout<<endl;}
}

