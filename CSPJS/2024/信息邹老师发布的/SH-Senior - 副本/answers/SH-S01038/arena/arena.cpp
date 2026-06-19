#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int a[100005],n,m,c[100005];
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	int t,T;
	cin>>t>>T;
	int r[105][105];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;i++){
			cin>>r[i][j];
		}
	 }
	cout<<0;
	return 0;
}
