#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5010],n,cnt=0;
bool book[5010];
void dfs(int x,int s,int maxs){
	if(x==n+1){
		if (s>maxs*2){
			cnt++;
			cnt%=mod;
		}
		return;
	}
	dfs(x+1,s+a[x],max(maxs,a[x]));
	dfs(x+1,s,maxs);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<cnt/2;
	return 0;
}
