#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510;
int n,m,c[N],ans,p[N],b[N];
string s;
void dfs(int x){
	if(x==n+1){
		int sum=0,qt=0;
		for(int i=1;i<=n;i++){
			if(qt>=c[p[i]]){
				qt++;
				continue;
			}
			if(s[i-1]=='0')qt++;
			else sum++;
		}
		if(sum>=m){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i])continue;
		p[x]=i;
		b[i]=1;
		dfs(x+1);
		b[i]=0;
		p[x]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
