#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],c[100005],r[500005],t,x[5],ans,y;
string s;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	y=n;
	while(y){
		cin>>s;
		y/=2;
	}
	cin>>t;
	while(t--){
		cin>>x[1]>>x[2]>>x[3]>>x[4];
		ans=0;
		for(int i=1;i<=m;i++)
			ans^=i*c[i];
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
