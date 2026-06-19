#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,a[510],c[510],v[510];
char s[510];
const long long md=998244353;
bool vs[510];
void dfs(long long x,long long y){
	if(x>n){
		if(y>=m)
			ans++;
		return;
	}
	for(int i=1;i<=n;++i){
		if(!vs[i]){
			if(c[i]<a[x-1]){
				vs[i]=1;
				dfs(x+1,y+1);
				vs[i]=0;
			}
			else{
				vs[i]=1;
				dfs(x+1,y);
				vs[i]=0;
			}
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	a[0]=0;
	for(int i=1;i<=n;++i){
		if(s[i-1]=='0')
			a[i]=a[i-1]+1;
		else
			a[i]=a[i-1];
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
		v[c[i]]++;
	}
	if(n-v[0]<=m)
		cout<<0;
	if(a[n]==0){
		ans=1;
		for(int i=1;i<=n;++i)
			ans=ans*i%md;
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
