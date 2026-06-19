#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[1000010],ans,v[1000010];
int dfs (int pos,int rl,int bl,int sum){
	if(pos==n+1)return sum;
	int m1=0,m2=0;
	if(rl==a[pos])m1=dfs(pos+1,rl,bl,sum+a[pos]);
	else m1=dfs(pos+1,a[pos],bl,sum);
	if(bl==a[pos])m2=dfs(pos+1,rl,bl,sum+a[pos]);
	else m2=dfs(pos+1,rl,a[pos],sum);
	return max(m1,m2);
}
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){cin>>a[i];}
		cout<<dfs(1,-1,-1,0)<<endl;
	}
	return 0;
}
