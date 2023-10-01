#include <stdio.h>
int *a;
int n, tmp;
int main(){
    // Tham Lap Phong - 20215449
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    //#Allocate memory
    a = new int[n];
    // Nhap mang
    for(int i = 0; i < n; i++)
        scanf("%d", a + i); 
    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    //Sap xep mang theo thu tu tang dan
    for (int i =0 ; i<n ; i++)
        for (int j = i; j<n; j++){
            if (*(a+i) > *(a+j) ){
                tmp = *(a+i);
                *(a+i) = *(a+j);
                *(a+j) = tmp;
            }
       }
    
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    //Giai phong bo nho
    delete [] a;
    return 0;
}
