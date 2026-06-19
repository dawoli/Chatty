#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,T,ans,a[N];
bool v[N];
void dfs(int i){
	if(i==n+1){
		int cnt=0;
		for(int j=1;j<=n;++j){
			for(int k=j-1;k>=1;--k)
				if(v[k]==v[j]&&a[j]==a[k]){
					cnt+=a[j];
					break;
				}	
		}
		ans=max(ans,cnt);
		return;
	}
	for(int k=0;k<=1;++k){
		v[i]=k;
		dfs(i+1);
		v[i]=0;
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	for(int i=1;i<=T;++i){
		cin>>n;
		for(int j=1;j<=n;++j)
			cin>>a[j];
		dfs(1);
		cout<<ans<<'\n';
		ans=0;
		for(int j=1;j<=n;++j)
			v[j]=0;
	}
	
	return 0;
}
