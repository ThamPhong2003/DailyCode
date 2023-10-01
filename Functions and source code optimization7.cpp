#include <iostream>
using namespace std;
//Tham Lap Phong 20215449
template <typename T>
T arr_sum(T a[], int n, T b[], int m) {
    T S = 0;
    for (int i = 0; i < n; i++)
        S += a[i];
    for (int i = 0; i < m; i++)
        S += b[i];
    return S;
}

int main() {
    int val;
    cin >> val;

    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}

