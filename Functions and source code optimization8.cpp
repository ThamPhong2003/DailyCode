#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h>
using namespace std;
//Tham Lap Phong 20215449
int main() {
    int val1, val2;
    cin >> val1 >> val2;
    vector<vector<int>> a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

  sort(a.begin(), a.end(), [](const vector<int> &x, const vector<int> &y) {
        int sum1 = accumulate(x.begin(), x.end(), 0);
        int sum2 = accumulate(y.begin(), y.end(), 0);
        return sum1 > sum2;
    });

    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}

