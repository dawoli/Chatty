#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10,B = 1131,P=998244353,M = 5e6 + 10;
inline int mul(int a,int b){return 1ll*a*b%P;}
int n,q;
string s1[N],s2[N];
namespace BF{
    void work(){
        string x,y;
        cin >> x >> y;
        if(x.size() != y.size()){cout << 0 << "\n";return;}
        int m = x.size(),cnt = 0;
        for(int p = 1; p <= n ; ++ p){
            int sz = s1[p].size();
            for(int i = 0; i < m ; ++ i){
                int j = (i + sz - 1);
                if(j >= m)break;
                if(x.substr(i,j-i+1) == s1[p]){
                    string r = (i ? x.substr(0,i) : "") + s2[p] + (j < m-1 ? x.substr(j+1) : "");
                    if(r == y)++cnt;
                }
            }
        }
        cout << cnt << "\n";
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n ; ++ i)cin >> s1[i] >> s2[i];
    if(n <= 100){
        while(q--){
            BF::work();
        }
    }else{
        while(q--){
            cout << 0 << "\n";
        }
    }
    return 0;
}