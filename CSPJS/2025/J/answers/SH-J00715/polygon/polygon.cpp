#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+3,MOD=998244353;
int n,siz=0;
long long ans;
int a[maxn],v[maxn];
void dfs(int u,int now,bool flg){
	if(flg){
		int id=lower_bound(a+1,a+n+1,now)-a-1;
		if((id)-(v[siz]+1)+1>0){
			ans+=(id)-(v[siz]+1)+1;
			ans%=MOD;
		}
	}
	if(u==n+1) return;
	dfs(u+1,now,0);
	v[++siz]=u;
	dfs(u+1,now+a[u],1);
	siz--;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flg=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flg=false;
	}
	if(flg){
		long long aa=n,bb=1;
		for(int i=2;i<n;i++){
			bb*=i;
			aa*=(n-i+1);
			ans+=aa/bb;
		}
		cout<<ans%MOD;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		siz=1;
		v[siz]=i;
		for(int j=i+1;j<=n;j++){
			siz=2;v[siz]=j;
			dfs(j+1,a[i]+a[j],1);
			siz=1;
		}
		siz=0;
	}
	cout<<ans%MOD;
	return 0;
}