#include<iostream>
#include<limits.h>
#include<cstring>
// Tham Lap Phong 20215449
using namespace std;
int d=0;
int n,r;
int c[101][101]={};
int marked[101]={};
int current[100]={};
int nguoi[101][101];
int best =INT_MAX;
int cmin=INT_MAX;
void setInput(){
    cin>>n>>r;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
            if((c[i][j]<cmin)&&(c[i][j]!=0)) cmin=c[i][j];
        }
}
bool isCandidate(int i,int r){
    bool inList=0;
    for(int j=1;j<=d-1;j++) if(nguoi[r][j]==i) inList= 1;
    if ((marked[i]==0)&&(inList)) return true;
    else return false;
}
void Try(int k,int r){
    static int value=0;
    if(k==2) {int i=1;while(nguoi[r][i]!=-1){d++;i++;}}  
    for(int i=1;i<=n;i++){
        
        if((isCandidate(i,r)&&c[current[k-1]][i]!=0)||((k==d)&& (i==nguoi[r][d])&&c[current[k-1]][i]!=0)){
            int tmp=value;
            marked[i]=1;
            current[k]=i;
            value=value+c[current[k-1]][i];
            if (k==d) {
            if(value<best) {best=value; }}
            else if(value+cmin*(d-k)>best) {
                marked[i]=0;
                current[k]=0;
                value=tmp;
                continue; }
                else Try(k+1,r);
                value=tmp;
                marked[i]=0;
                current[k]=0;
                }
    }
} 
int main(){
    
    setInput();
    memset(nguoi,-1,sizeof(nguoi));
    char x;
    int dem=1; 
    for(int j=1;j<=r;j++){
    do {
        cin>>nguoi[j][dem];
        dem++;
        x=getchar();
    }while(x!='\n'); dem=1;}
    for(int j=1;j<=r;j++) {
        current[1]=nguoi[j][1];
        marked[current[1]]=1;
        Try(2,j);
        if(best!=INT_MAX) cout<<best<<endl;
        else cout<<0<<endl;
        memset(marked,0,sizeof(marked));
        memset(current,0,sizeof(marked));
        best =INT_MAX;d=0;}
}

