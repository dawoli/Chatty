#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M=998244353;
void Mod(ll &x) {
	if(x>=M) x-=M;
}

void read(ll &x) {
    x=0;
    char c=getchar();
    while(!('0'<=c && c<='9')) c=getchar();
    while('0'<=c && c<='9') {
        x=x*10+c-'0';
        c=getchar();
    }
}
 
const int maxn=512;

int n, m;
bool d[maxn];
int p[maxn];
int c[maxn];

vector<int> bt[20];

ll dp[20][20][(1<<18)+20];

int main()
{
	clock();
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin>>n>>m; 
    if(n>18) {
    	cout<<0;
    	return 0;
	}
    char ch=getchar();
    while(ch!='0' && ch!='1') ch=getchar();
    int tot=0, cnt=0;
    for(int i=1;i<=n;i++) {
        if(ch=='0') ++tot;
        else p[++cnt]=tot;
        ch=getchar();
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=(1<<18)-1;i>=0;--i) bt[__builtin_popcount(i)].push_back(i);
	dp[0][0][0]=1;
	for(int i=1;i<=cnt;i++) {
		for(int j=0;j<i;j++) {
			for(int x=1;x<=n;x++) {
				for(auto s:bt[i-1]) {
					if(s&(1<<(x-1))) continue;
					if(c[x]-p[i]<=j) {
						dp[i][j+1][s|(1<<(x-1))]+=dp[i-1][j][s], Mod(dp[i][j+1][s|(1<<(x-1))]);
					}
					else {
						dp[i][j][s|(1<<(x-1))]+=dp[i-1][j][s], Mod(dp[i][j][s|(1<<(x-1))]);
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=n-m-tot;i++) {
		for(auto s:bt[cnt]) ans+=dp[cnt][i][s], Mod(ans);
	}
	for(ll i=tot;i>=2;--i) {
		ans*=i;
		if(ans>=M) ans%=M;
	}
	cout<<ans;
    return 0;
}
