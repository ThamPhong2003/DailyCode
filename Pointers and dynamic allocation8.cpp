#include <stdio.h>
//Tham Lap Phong - 20215449
void allocate_mem(int ***mt, int m, int n){
    //Cap phat bo nho dong cho mang 2 chieu
    *mt = new int *[m];
    for(int i=0; i<m; i++){
        (*mt)[i] = new int[n];
    }
}
    // Nhap mang 2 chieu
void input(int **mt, int m, int n){
   for (int i =0 ; i<m; i++)
    for (int j =0 ; j<n;j++){
       printf ("mt[%d][%d] = ",i,j);
       scanf("%d",&mt[i][j]); 
    }
}
    // in ra mang 2 chieu
void output(int **mt, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
        printf("%d ",mt[i][j]);
        printf("\n");
    }
}
    //Ham dua ra tong cac phan tu chan trong mang
int process(int **mt, int m, int n){
    int tong = 0;
    for (int i =0 ; i< n; i++)
    for (int j =0 ; j<n; j++){
        if ( mt[i][j] %2 ==0){
            tong = tong + mt[i][j];
        }
    }
    return tong;
}
    //Ham giai phong bo nho
void free_mem(int **mt, int m, int n){
    //# Free memory
    for(int i=0; i<m; i++)
    delete [] mt[i];
    delete [] mt;
}

int main(){
    int m, n, **mt;
    printf("Enter m, n = ");
    scanf("%d%d", &m, &n);
    allocate_mem(&mt, m, n);
    input(mt, m, n);
    output(mt, m, n);
    printf("The sum of all even elements is %d", process(mt, m, n));
    free_mem(mt, m, n);
    return 0;
}
