//Pavel to Ivan
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<vector<double>> matrix_mult(vector<vector<double>> A, vector<vector<double>> B) {
    int m = A.size();
    int n = B[0].size();
    int p = B.size();
    vector<vector<double>> C(m, vector<double>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main() {
    // Матрица перехода
    vector<vector<double>> T {{cos(theta1), sin(theta1), 0},
                              {-sin(theta2), cos(theta2), 0},
                              {0, 0, 1}};
    // координаты в оригинальной СК
    vector<double> coords_orig {x, y, z};
    // расчет новых координат, для новой СК
    vector<double> coords_new = matrix_mult(T, coords_orig);
    cout << "Координаты в новой СК: (" << coords_new[0] << ", " << coords_new[1] << ", " << coords_new[2] << ")" << endl;
    return 0;
}
