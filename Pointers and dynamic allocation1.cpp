# include <stdio.h>
int main(){
    // Tham Lap Phong - MSSV: 20215449
    int x, y, z;
    int* ptr;
    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("\nThe three integers are:\n");
    /*chuong tr�nh C nh?p v�o 3 s? nguy�n. Thi?t l?p m?t con tr? d?
    l?n lu?t tr? t?i t?ng s? nguy�n v� hi?n th? k?t qu? gi� tr? tham chi?u ngu?c c?a con tr?.*/
    ptr = &x;
    printf("x = %d\n", *ptr);
    ptr = &y;
    printf ("y = %d\n",*ptr);
    ptr = &z;
    printf ("z = %d\n",*ptr);
    
    return 0;
}
