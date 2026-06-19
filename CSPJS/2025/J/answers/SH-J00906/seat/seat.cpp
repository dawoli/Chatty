#include<bits/stdc++.h>
using namespace std;
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
#define int long long
#define N 111
int n,m,a[N][N],s[N];
signed main(){
	open("seat");
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i];
	int k=s[1];
	sort(s+1,s+1+n*m,greater<int>());
	int it=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			++it,a[i&1?j:n+1-j][i]=s[it];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]==k)cout<<j<<' '<<i<<endl;
}
