#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[114514],cnt=0;
void dfs(int x,int m,int l,int maxl){
	if(x>n)return;
	dfs(x+1,m,l,maxl);
	l+=a[x];
	m++;
	maxl=max(maxl,a[x]);
	if(m>=3&&l>2*maxl){
		cnt++;
		cnt%=mod;
	}
	dfs(x+1,m,l,maxl);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	dfs(0,0,0,0);
	cout<<cnt/2;
}
