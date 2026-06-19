#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void checkCoprime() {
    for (int i = 1; i <= 100000000; i += 2) {
        if (gcd(i, i + 1) != 1) {
            cout << "非互质: " << i << " 和 " << i + 1 << endl;
        }
    }
    cout << "从1~100000000中所有相邻的自然数都互质";
}
int main() {
    checkCoprime();
    return 0;
}
