# include <stdio.h>
int main(){
    // Tham Lap Phong - MSSV: 20215449
    int x, y, z;
    int* ptr;
    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("\nThe three integers are:\n");
    /*chuong trình C nh?p vào 3 s? nguyên. Thi?t l?p m?t con tr? d?
    l?n lu?t tr? t?i t?ng s? nguyên và hi?n th? k?t qu? giá tr? tham chi?u ngu?c c?a con tr?.*/
    ptr = &x;
    printf("x = %d\n", *ptr);
    ptr = &y;
    printf ("y = %d\n",*ptr);
    ptr = &z;
    printf ("z = %d\n",*ptr);
    
    return 0;
}
