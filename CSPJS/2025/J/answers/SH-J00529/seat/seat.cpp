#include <bits/stdc++.h>

using namespace std;

struct Sc {
    short val;
    bool is_r;
};

Sc matrix[150]{};

int main() {
    ifstream in("seat.in");
    ofstream out("seat.out");
    int n, m;
    in >> n >> m;
    for (int i = 0; i < n*m; i++) {
        int sc;
        in >> sc;
        matrix[i] = {(short)sc, i == 0};
    }
    sort(matrix, matrix + n*m, [](auto s1, auto s2) {
        return s1.val > s2.val;
    });
    for (int i = 0; i < n*m; i++) {
        if (matrix[i].is_r) {
            int mix = i/n;
            int nix = i/m;
            if ((mix & 1) == 0) {
                nix = m - nix - 1;
            }
            out << (mix + 1) << ' ' << (nix + 1) << endl;
            return 0;
        }
    }
    return 0;
}