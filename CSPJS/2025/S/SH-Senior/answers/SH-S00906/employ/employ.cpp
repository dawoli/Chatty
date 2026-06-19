#include<bits/stdc++.h>
using namespace std;
constexpr int mod=998244353;
int c[501],n,m;
bitset<501> pass,vis;
int dfs(int now=1,int lost=0){
	if(now>n) return (n-lost>=m);
	int sum=0;
	for(int i=0;i<n;++i){
		if(!vis[i]){
			vis[i]=1;
			sum+=dfs(now+1,max(1-pass[now-1],int(lost>=c[i]))+lost);
			vis[i]=0;
		}
	}
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool specA=true;
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=0;i<n;++i){
		char c=getchar();
		pass[i]=(c=='1');
		if(specA && pass[i]!=1) specA=false; 
	}
	for(int i=0;i<n;++i) {
		scanf("%d",c+i);
	}
	if(n<=10){
		cout<<dfs();
	}
	else{
		int minn=1;
		while(minn-1<n && pass[minn-1]) minn++;
		minn--;
		if(minn<m) cout<<0;
		else{
			long long pro=1;
			for(int i=1;i<=n;++i) pro=pro*i%mod;
			cout<<pro; 
		}
	}
	return 0;
}
