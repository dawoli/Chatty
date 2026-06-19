#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long len[10000]={0},n;
long long dfs(long long pos,long long sum,long long Max){
	if(pos==n+1){
		if(sum>Max*2){
			return 1;
		}else return 0;
	}
	return (dfs(pos+1,sum,Max)%mod+dfs(pos+1,sum+len[pos],max(Max,len[pos]))%mod)%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>len[i];
	cout<<dfs(1,0,0);
	return 0;
}
