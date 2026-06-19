#include <bits/stdc++.h>
using namespace std;
int n,cnt;
// string poker[60];
// string Color[4] = {"D","C","H","S"};
// string Num[13] = {"A","2","3","4","5","6","7","8","9","T","J","Q","K"};
set<string> PokerWhole,PokerGet;
int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    // for (auto a : Color) {
    //     for (auto b : Num) {
    //         PokerWhole.insert(a+b);
    //     }
    // }
    for (int i=1; i<=n; ++i) {
        string pok;
        cin >> pok;
        // if (PokerWhole.count(pok)) {
        //     ;
        // }
        PokerGet.insert(pok);
    }
    printf("%d\n",52-PokerGet.size());
    return 0;
}