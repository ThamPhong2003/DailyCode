#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
using namespace std;
//??nh ngh?a l?i so sánh trong priority queue
//priority queue ch?a các c?p (x,y) trong ?ó x là s? hi?u v?n b?n, y là ?i?m s? c?a v?n b?n ?ó
struct cmp{
   bool operator () (pair<int,int> x,pair<int,int> y){
      //V?n b?n ?i?m cao s? ? trên cùng  
      if( x.second>y.second) return false;
      //2 v?n b?n cùng ?i?m thì v?n b?n có s? hi?u th?p h?n s? ? trên
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
// Tìm max f(t,d) v?i m?i t thu?c v?n b?n d
int max(int d,vector<vector<string>> &a){
    //1 t? s? t??ng ?ng v?i s? l?n nó xu?t hi?n
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
                //có ch?a t break sang v?n b?n ti?p theo
                dem++;
                break;}
        }
    }
    return dem;
}
//Hàm tính ?i?m v?n b?n d v?i t? t
double tscore(string t,int d,vector<vector<string>> &a,int N){
    //t không xu?t hi?n trong d thì ?i?m b?ng 0
    if (f(t,d,a)==0) return 0;
    //Tính ?i?m theo công th?c
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
    //VB ch?a các vector là các v?n b?n, các vector ?ó ch?a các t? trong v?n b?n
    vector<vector<string>> VB;
    VB.resize(N);
    //Nh?p các v?n b?n
    for(int i=0;i<N;i++){
        string str;
        str.resize(10);
        char c;
        //Bi?n dem dùng ?? nh?p kí t? vào xâu
        int dem=0;
        L0: do{
            c=getchar();
            if(c=='\n') goto L1;//c là xu?ng dòng thì nha? L1:cho xâu ?ang dang d? thành 1 t? vào v?n b?n hi?n th?i,b? ??m v? 0,reset str
            else if(c==',') goto L2;//c là d?u ph?y thì l?u xâu ?ó thành m?t t?, dem v? 0,reset str và quay L0 b?t ??u t? ti?p theo
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
    //Nh?p các truy v?n t??ng t? nh?p v?n b?n
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
    //Hàng ??i ?u tiên
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    //V?i m?i truy v?n 
    for(auto x:TV){
        //V?i m?i v?n b?n i
        for(int i=0;i<N;i++){
            double score=0;
            //V?i m?i t? y thu?c truy v?n x ta tính ?i?m v?i t?ng v?n b?n i và c?ng d?n l?i
            for(auto y:x){
                score=score+tscore(y,i,VB,N);
            }
            //Ta ??y ?i?m c?a v?n b?n i v?i truy v?n x và hàng ??i
            pq.push(make_pair(i,score));
        }
        //L?y ra ??nh c?a hàng ??i chính là ?i?m cao nh?t v?i truy v?n x, ta c?ng 1 do truy v?n ?ánh s? t? 1
        cout<<pq.top().first+1<<endl;
        //xóa hàng ??i chu?n b? sang truy v?n ti?p theo 
         while(!pq.empty()) {pq.pop();}
    }
}

