#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
using namespace std;
//??nh ngh?a l?i so s�nh trong priority queue
//priority queue ch?a c�c c?p (x,y) trong ?� x l� s? hi?u v?n b?n, y l� ?i?m s? c?a v?n b?n ?�
struct cmp{
   bool operator () (pair<int,int> x,pair<int,int> y){
      //V?n b?n ?i?m cao s? ? tr�n c�ng  
      if( x.second>y.second) return false;
      //2 v?n b?n c�ng ?i?m th� v?n b?n c� s? hi?u th?p h?n s? ? tr�n
      else if(x.second==y.second) if(x.first<y.first) return false;
                                    else return true;
      else return true;
   }
};
//So lan xuat hien t trong d
int f(string t,int d,vector<vector<string>> &a){
    int dem=0;
    for(string x: a[d]) {if(t==x) dem=dem+1;}
    return dem;
}
// T�m max f(t,d) v?i m?i t thu?c v?n b?n d
int max(int d,vector<vector<string>> &a){
    //1 t? s? t??ng ?ng v?i s? l?n n� xu?t hi?n
    map<string,int> M;
    for(string x:a[d]) M[x]++;
    int max=0;
    for(auto x:M) {
        //max ch?a s? l?n xu?t hi?n nhi?u nh?t c?a t? xu?t hi?n nhi?u nh?t
        if (x.second>max) max=x.second;
    }
    return max;
}
//S? v?n b?n ch?a t? t
int df(string t,vector<vector<string>> &a){
    int dem=0;
    for(auto x:a){
        for(auto y:x){
            if(y==t) {
                //c� ch?a t break sang v?n b?n ti?p theo
                dem++;
                break;}
        }
    }
    return dem;
}
//H�m t�nh ?i?m v?n b?n d v?i t? t
double tscore(string t,int d,vector<vector<string>> &a,int N){
    //t kh�ng xu?t hi?n trong d th� ?i?m b?ng 0
    if (f(t,d,a)==0) return 0;
    //T�nh ?i?m theo c�ng th?c
    double TF=0.5+0.5*f(t,d,a)/max(d,a);
    double IDF=log2(N/df(t,a));
    return TF*IDF;
}
int main(){
    //Nh?p d? li?u t? file input.txt
    freopen("input.txt","r",stdin);
    int N,Q;
    cin>>N;
    getchar();
    //VB ch?a c�c vector l� c�c v?n b?n, c�c vector ?� ch?a c�c t? trong v?n b?n
    vector<vector<string>> VB;
    VB.resize(N);
    //Nh?p c�c v?n b?n
    for(int i=0;i<N;i++){
        string str;
        str.resize(10);
        char c;
        //Bi?n dem d�ng ?? nh?p k� t? v�o x�u
        int dem=0;
        L0: do{
            c=getchar();
            if(c=='\n') goto L1;//c l� xu?ng d�ng th� nha? L1:cho x�u ?ang dang d? th�nh 1 t? v�o v?n b?n hi?n th?i,b? ??m v? 0,reset str
            else if(c==',') goto L2;//c l� d?u ph?y th� l?u x�u ?� th�nh m?t t?, dem v? 0,reset str v� quay L0 b?t ??u t? ti?p theo
            else{
                str[dem]=c;
                dem++;}
        }while(1);
        L2:{
            VB[i].push_back(str);
            dem=0;
            str.clear();
            str.resize(10);
            goto L0;};
        L1:{
            VB[i].push_back(str);
            dem=0;
            str.clear();
            str.resize(10);
        };
    }
    //Nh?p c�c truy v?n t??ng t? nh?p v?n b?n
    cin>>Q;
    getchar();
    vector<vector<string>> TV;
    TV.resize(Q);
    for(int i=0;i<Q;i++){
        string str;
        str.resize(10);
        char c;
        int dem=0;
        L3: do{
            c=getchar();
            if(c=='\n') goto L4;
            else if(c==',') goto L5;
            else{
                str[dem]=c;
                dem++;}
        }while(1);
        L5:{
            TV[i].push_back(str);
            dem=0;
            str.clear();
            str.resize(10);
            goto L3;};
        L4:{
            TV[i].push_back(str);
            dem=0;
            str.clear();
            str.resize(10);
        };
    }
    //H�ng ??i ?u ti�n
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    //V?i m?i truy v?n 
    for(auto x:TV){
        //V?i m?i v?n b?n i
        for(int i=0;i<N;i++){
            double score=0;
            //V?i m?i t? y thu?c truy v?n x ta t�nh ?i?m v?i t?ng v?n b?n i v� c?ng d?n l?i
            for(auto y:x){
                score=score+tscore(y,i,VB,N);
            }
            //Ta ??y ?i?m c?a v?n b?n i v?i truy v?n x v� h�ng ??i
            pq.push(make_pair(i,score));
        }
        //L?y ra ??nh c?a h�ng ??i ch�nh l� ?i?m cao nh?t v?i truy v?n x, ta c?ng 1 do truy v?n ?�nh s? t? 1
        cout<<pq.top().first+1<<endl;
        //x�a h�ng ??i chu?n b? sang truy v?n ti?p theo 
         while(!pq.empty()) {pq.pop();}
    }
}

