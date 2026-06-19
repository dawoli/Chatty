#include <iostream>
#include <string>
#include <cstdio>
#include <unordered_set>
using namespace std;
bool maps[1001][1001];
int n,m,k,t = 0;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int ljk = 0;
unordered_set<long long> st[5];

void dg(int pstx, int psty, int pstd){
    st[t].insert(pstx * 10000 + psty);
    if(ljk == k) return;

    int amx = pstx + dx[pstd];
    int amy = psty + dy[pstd];

    if(maps[amx][amy] == true or amx <= 0 or amy <= 0 or amx > n or amy > m){
        ljk++;
        //cout << ljk << " " << pstx << " " << psty << " zx "<< (pstd + 1) % 4 << endl;
        dg(pstx, psty, (pstd + 1) % 4);
    }
    else{
        ljk++;
        //cout << ljk << " " << pstx << " " << psty << " goto "<< amx << " " << amy << endl;
        dg(amx, amy, pstd);
    }

}

int core(){
    cin >> n >> m >> k;
    int x0, y0, d0; cin >> x0 >> y0 >> d0;

    for(int i = 1; i <= n; i++){
        string a; cin >> a;
        for(int j = 0; j <= a.length() - 1; j++){
            if(a[j] == '.') {
                maps[i][j + 1] = false;
            }
            if(a[j] == 'x') {
                maps[i][j + 1] = true;
            }
        }
    }

    dg(x0, y0, d0);

    return st[t].size();
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int T; cin >> T;
    for(t = 0; t < T; t++){
        cout << core() << endl;
        ljk = 0;
    }
    return 0;
}
