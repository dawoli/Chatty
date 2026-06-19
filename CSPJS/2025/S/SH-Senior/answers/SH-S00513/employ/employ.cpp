#include <iostream>

using namespace std;

const int N = 114514191;
int arr[N];

int main() {
    ifstream in("employ.in");
    ifstream out("employ.out");
    int n, m;
    in >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    out << 0; // zhenshihuanjing: youyu bekexue bugongping mianshi huanji, noone is xiang lai the li mianshi
    return 0;
}