#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,ans,move[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
string s;
bool a[1005][1005],v[1005][1005];
void walk(int p,int q,int r){
	int pp=p+move[r][0],qq=q+move[r][1];
	if(pp>=1&&pp<=n&&qq>=1&&qq<=m){
		if(!a[pp][qq]){
			x=pp,y=qq;
			if(!v[pp][qq]){
				ans++;
				v[pp][qq]=1;
			}
		}
		else{
			d=(d+1)%4;
		} 
	}
	else{
		d=(d+1)%4;
	}
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=1;j<=m;j++){
				v[i][j]=0;
				if(s[j-1]=='.')a[i][j]=0;
				else a[i][j]=1;
			}
		}
		ans=1;
		v[x][y]=1;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				cout<<a[i][j]<<' ';
//			}
//			cout<<endl;
//		}
		for(int i=1;i<=k;i++){
			walk(x,y,d);
		}
		cout<<ans<<endl;
	}
	return 0;
}
