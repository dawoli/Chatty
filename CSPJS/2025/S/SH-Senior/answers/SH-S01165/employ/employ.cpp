#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=505,mod=998244353;

int n,m,c[N];
char s[N];
int res;
int p[N],st[N];

void dfs(int u){
	if(u>n){
		int cnt=0;
		for(int i=1; i<=n; i++){
			if(s[i]=='0'||cnt>=c[p[i]]) cnt++;
		}
		if(cnt<=n-m) res=(res+1)%mod;
	}
	for(int i=1; i<=n; i++){
		if(st[i]) continue;
		st[i]=1,p[u]=i;
		dfs(u+1);
		st[i]=0;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m>>s+1;
	for(int i=1; i<=n; i++) cin>>c[i];
	dfs(1);
	cout<<res;
	return 0;
}
