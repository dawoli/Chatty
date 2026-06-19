#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int read() {
    int x=0, f=1;
    char ch=getchar();
    while (!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
    while (isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
    return x*f;
}
void print(int x) {
    if (x<0) {putchar('-'); return;}
    if (x<10) {putchar(x+'0'); return;}
    else {print(x/10); putchar(x%10+'0'); return;}
}
int t, n, k, ans;
int a[MAXN][4];
vector<int> G[4];
void init() {
    G[1].clear(); G[2].clear(); G[3].clear();
//    memset(a, 0, sizeof a);
    n=k=ans=0;
}
pair<int, int> cmp(int x, int y, int z) {
    if (x>y) {
        if (x>z) return make_pair(min(x-y, x-z), 1);
        else return make_pair(z-x, 3);
    }
    else {
        if (y>z) return make_pair(min(y-x, y-z), 2);
        else return make_pair(z-y, 3);
    }
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    t=read();
    while (t--) {
        init();
        n=read();
        k=n/2;
        for (int i=1; i<=n; i++) {
            a[i][1]=read(), a[i][2]=read(), a[i][3]=read();
            pair<int, int> p=cmp(a[i][1], a[i][2], a[i][3]);
            ans+=a[i][p.second];
            G[p.second].push_back(p.first);
        }
        for (int i=1; i<=3; i++) {
            if (G[i].size()>k) {
                int res=G[i].size()-k;
                sort(G[i].begin(), G[i].end());
                for (int j=0; j<res; j++) ans-=G[i][j];
            }
        }
        print(ans);
        putchar('\n');
    }

}
