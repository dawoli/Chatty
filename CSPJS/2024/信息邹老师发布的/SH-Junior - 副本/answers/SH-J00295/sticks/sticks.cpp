#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int T,n,f[N],num[10]={6,2,5,5,4,5,6,3,7,6};
void dfs(int n){
	for(int i=0;i<10;i++)
		if(f[n]==f[n-num[i]]+1){
			cout<<i;
			dfs(n-num[i]);
			return;
		}
}
void solve(){
	cin>>n;
	int minn=1e9;
	for(int i=1;i<10;i++)
		if(n>=num[i]) minn=min(minn,f[n-num[i]]+1);
	if(minn==1e9){
		cout<<-1<<'\n';
		return;
	}
	for(int i=1;i<10;i++)
		if(n>=num[i]&&minn==f[n-num[i]]+1){
			cout<<i;
			dfs(n-num[i]);
			cout<<'\n';
			return;
		}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	for(int i=1;i<=1e5;i++) f[i]=1e9;
	f[0]=0;
	for(int i=1;i<=1e5;i++)
		for(int j=0;j<10;j++)
			if(i>=num[j]) f[i]=min(f[i],f[i-num[j]]+1);
	cin>>T;
	while(T--) solve();
	return 0;
} 
