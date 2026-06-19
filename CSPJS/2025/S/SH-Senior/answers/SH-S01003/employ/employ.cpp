#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=505,md=998244353;
int n,m;
int dif[N];
int c[N];
bool tepan=1;
int cnt;
int fir;

int tmp[N];
bool vis[N];
int ans;

bool check(){
	int cnt=0,res=0;;
	for(int i=1;i<=n;i++){
		if(cnt<=c[tmp[i]] and dif[i]==1){
			res++;
		}
		else{
			cnt++;
		}
	}
	return res>=m;
}
void dfs(int k){
	if(k==n+1){
		if(check()){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			tmp[k]=i;
			dfs(k+1);
			tmp[k]=0;
			vis[i]=0;
		}
	}
	return ;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;cin>>c;
		dif[i]=c-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		c[i]--;
	}
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}

