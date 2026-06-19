#include <bits/stdc++.h>

using namespace std;

// 5
int bucket[15]{};

int main() {
    ifstream in("number.in");
    ofstream out("number.out");
    char ch;
    while (in >> ch) {
        if (ch <= '9' && ch >= '0') {
            bucket[ch - '0']++;
        }
    }
    for (int i = 9; i >= 0; --i) {
        while (bucket[i]--) out << i;
    }
    out << endl;
    return 0;
}
