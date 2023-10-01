#include <stdio.h>
//Tham Lap Phong - 20215449
int cube(int x) {
  return x*x*x;
}

double cube(double y){
    return y*y*y;
}

int main() {
    int n;
    double f;
    scanf("%d %lf", &n, &f);
    
    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));
    
    return 0;
}
