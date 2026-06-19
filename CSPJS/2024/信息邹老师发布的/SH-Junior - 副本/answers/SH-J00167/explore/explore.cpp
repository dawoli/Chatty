#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],mm[1005][1005];
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;cin>>t;
	while(t>0){
	int n,m,k,x,y,d;
	cin>>n>>m>>k>>x>>y>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char ch;cin>>ch;
			if(ch=='.') a[i][j]=1;
			else if(ch=='x') a[i][j]=0;
		}
	} 
	mm[x][y]=1;
	while(k>0){
		if(a[x+xx[d]][y+yy[d]]==0){
			d++;d%=4;
		}
		else{
			x+=xx[d];y+=yy[d];
			mm[x][y]=1;
		}
		k--;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mm[i][j]==1){
				ans++;
				mm[i][j]=0;
				a[i][j]=0;}
	cout<<ans<<endl;
	t--;
	}
	return 0;
}
