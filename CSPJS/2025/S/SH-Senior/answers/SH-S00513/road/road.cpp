#include <iostream>

using namespace std;

int64_t fund = 1145141919810;

int take_tax() {
    while (fund < 0) {
        fund += rand();
    }
    return fund > 0 ? 0 : abort();
}

int main() {
    ifstream in("road.in");
    ofstream of("road.out");

    int n, m, k;
    in >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int peki, syah, w;
        cin >> peki >> syah >> w;
        fund -= w;
    }

    of << (fund < 0 ? take_tax() : 0) << endl;
}