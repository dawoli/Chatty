#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;++i){
		int n,m,k,cnt=1,x0,y0,d0,flag[1010][1010];
		string s[1010];
		cin>>n>>m>>k>>x0>>y0>>d0;
		for(int j=0;j<n;++j) cin>>s[j]; 
		int x,y;
		if(d0==0) x=x0,y=y0+1;
		if(d0==1) x=x0+1,y=y0;
		if(d0==2) x=x0,y=y0-1;
		if(d0==3) x=x0-1,y=y0;
		if(x<=n&&x>=1&&y>=1&&y<=m&&s[x-1][y-1]=='.') ++cnt;
		cout<<cnt<<"\n"; 
	}
	return 0;
}
