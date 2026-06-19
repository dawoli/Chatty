#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string In;
int n,cnt;
string cards[60];

int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> In;
        bool ok=1;
        for (int i=1;i<=cnt;i++) {
            if (In==cards[i]) {
                ok=0;
                break;
            }
        }
        if (ok) cards[++cnt]=In;
    }
    cout << 52-cnt;
}
