#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int n;
bool D[14], C[14], H[14], S[14];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin >> n;
    for(int i = 0; i < n; i++){
        string a1; cin >> a1;
        int tgt = 0;
        if(a1[1] == 'T') tgt = 10;
        else if(a1[1] == 'J') tgt = 11;
        else if(a1[1] == 'Q') tgt = 12;
        else if(a1[1] == 'K') tgt = 13;
        else if(a1[1] == 'A') tgt = 1;
        else tgt = a1[1] - '0';
        //cout << a1[i] << tgt << endl;
        if(a1[0] == 'D') D[tgt] = true;
        if(a1[0] == 'C') C[tgt] = true;
        if(a1[0] == 'H') H[tgt] = true;
        if(a1[0] == 'S') S[tgt] = true;
    }

    int cnt = 0;
    for(int i = 1; i <= 13; i++){
        if(D[i] == false) cnt++;
        if(C[i] == false) cnt++;
        if(H[i] == false) cnt++;
        if(S[i] == false) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
