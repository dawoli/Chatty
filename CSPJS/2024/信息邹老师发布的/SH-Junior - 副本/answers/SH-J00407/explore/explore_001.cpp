#include<bits/stdc++.h>
using namespace std;
void solve(){
	long long cnt=0;
	int n,m,k;
	int sx,sy,sd;
	bool mp[1010][1010];
	bool vis[1010][1010];
	for(int i=0;i<=1001;i++){
		for(int j=0;j<=1001;j++){
			mp[i][j]=false;
			vis[i][j]=false;
		}
	}
	cin>>n>>m>>k;
	cin>>sx>>sy>>sd;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;
			cin>>c;
			if(c=='x'){
				mp[i][j]=false;
			}
			else{
				mp[i][j]=true;
			}
		}
	}
	for(int K=1;K<=k+1;K++){
		//cout<<sx<<" "<<sy<<" "<<sd<<" -> ";
		if(!vis[sx][sy]){
			cnt++;
		}
		vis[sx][sy]=true;
		int aimx=sx,aimy=sy;
		if(sd==0) aimy++;
		else if(sd==1) aimx++;
		else if(sd==2) aimy--;
		else if(sd==3) aimx--;
		//cout<<aimx<<" "<<aimy<<endl;
		if(aimx>=1&&aimx<=n&&aimy>=1&&aimy<=m&&mp[aimx][aimy]){
			sx=aimx;
			sy=aimy;
		}
		else{
			sd=(sd+1)%4;
		}
	}
	cout<<cnt<<endl;
	return ;
}
signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		solve();
	}
	return 0;
}
