#include<bits/stdc++.h>
using namespace std;
int a[4][2]={0,1,1,0,0,-1,-1,0};
int ans=0;
void w(){
	
	int n,m,k,x,y,d;
	cin>>n>>m>>k;
	char s[n+10][m+10];
	int v[n+10][n+10];
	cin>>x>>y>>d;
	v[x][y]=1;
	ans++;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		cin>>s[i][j];
		v[i][j]=0;
	}
	for(int i=0;i<k;i++){
		if(s[x+a[d][0]][y+a[d][1]]=='.'){
			x=x+a[d][0];
			y+=a[d][1];
			if(v[x][y]==0){
				ans++;
				v[x][y]=1;
			}
		}
		else{
			d=(d+1)%4;
		}
	}
	cout<<ans<<endl;
	ans=0;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		w();
	}
	return 0;
}
