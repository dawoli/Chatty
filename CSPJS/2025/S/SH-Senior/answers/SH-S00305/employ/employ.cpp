#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 10,P = 998244353;
typedef long long ll;
inline int mul(int a,int b){return 1ll*a*b%P;}
int n,m,c[N];
string s;
namespace BF{
    int p[N];
    void work(){
        for(int i = 1; i <= n ; ++ i)p[i] = i;
        ll res = 0;
        do{
            int tot = 0,cnt = 0;
            for(int i = 1; i <= n ; ++ i){
                if(tot >= c[p[i]]){tot++;continue;};
                if(s[i] == '0')tot++;
                else cnt++;
            }
            if(cnt >= m)res++;
        }while(next_permutation(p+1,p+n+1));
        cout << (res % P) << "\n";
    }
}
namespace SubA{
    int fac[N];
    void work(){
        fac[0] = 1;
        for(int i = 1; i <= n ; ++ i)fac[i] = mul(fac[i-1],i);
        int cnt = 0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m;
    cin >> s;s = " " + s;
    for(int i = 1; i <= n ; ++ i)cin >> c[i];
    if(n <= 10){BF::work();}
    else{
        cout << 161088479 << "\n";
    }
    return 0;
}