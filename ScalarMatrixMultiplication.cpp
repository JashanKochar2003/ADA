#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void print(const vector<vector<int>>& s, int i, int j) {
    if (i == j)
        cout << "A" << i - 1;
    else {
        cout << "(";
        print(s, i, s[i][j]);
        print(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void MatrixChainOrder(vector<int>& p) {
    int n = p.size();
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    for (int l = 2; l < n; l++)
        for (int i = 1, j = i + l - 1; i < n - l + 1; i++, j = i + l - 1) {
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }

    cout << m[1][n - 1] << endl;
    print(s, 1, n - 1);
    cout << endl;
}

int main() {
    vector<int> p = {10,13,21,57,68};

    MatrixChainOrder(p);
    return 0;
}