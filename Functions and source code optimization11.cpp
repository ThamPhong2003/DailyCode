#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply_polynomials(const vector<int>& A, const vector<int>& B) {
    int N = A.size();
    int M = B.size();
    int degree = N + M - 1;
    vector<int> C(degree, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            C[i + j] += A[i] * B[j];
        }
    }

    return C;
}

int calculate_xor(const vector<int>& polynomial) {
    int result = 0;
    for (int i = 0; i < polynomial.size(); i++) {
        result ^= polynomial[i];
    }
    return result;
}

int main() {
    int N, M;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 0; i <= N; i++) {
        cin >> A[i];
    }

    cin >> M;
    vector<int> B(M + 1);
    for (int i = 0; i <= M; i++) {
        cin >> B[i];
    }

    vector<int> C = multiply_polynomials(A, B);

    int xor_sum = calculate_xor(C);

    cout << xor_sum << endl;

    return 0;
}

