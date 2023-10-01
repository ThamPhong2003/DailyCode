#include <stdio.h>
int main(){
    //Tham Lap Phong - MSSV :20215449
    int x, y, z;
    int *ptr;
    scanf("%d %d %d", &x, &y, &z);
    printf("Here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);

    ptr = &x;   // truy cap den dia chi bien x
    *ptr = *ptr + 100; //cong gia tri bien x len 100
    ptr = &y;   // truy cap den dia chi bien y
    *ptr = *ptr + 100; //cong gia tri bien y len 100
    ptr = &z; // truy cap den dia chi bien z
    *ptr = *ptr + 100; //cong gia tri bien z len 100
    
    printf("Once again, here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);
    return 0;
}   
