#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,x,y,d,ans,ans1;
int mp[1009][1009],cnt[1009][1009];

void solve(){
	int f=0;
	ans1=1;
	cin>>n>>m>>k;
	cin>>x>>y>>d;
	cnt[x][y]=1;
	int _x=x,_y=y;
	memset(mp,-1,sizeof(mp));
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<=1+m;i++)mp[0][i]=-1;
	for(int i=0;i<=1+m;i++)mp[n+1][i]=-1;
	for(int i=0;i<=1+n;i++)mp[i][m+1]=-1;
	for(int i=0;i<=1+n;i++)mp[i][0]=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;
			cin>>c;
			if(c=='.')mp[i][j]=0;
		}
	}
	if(k==1){
		int x_=x,y_=y;
		if(d==0)y_++;
		if(d==2)y_--;
		if(d==1)x_++;
		if(d==3)x_--;
		if(mp[x_][y_]!=-1){
			x=x_,y=y_;
			ans++;
		}
		cout<<ans<<endl;
		return;
	}
	while(k--){
		int x_=x,y_=y;
		if(d==0)y_++;
		if(d==2)y_--;
		if(d==1)x_++;
		if(d==3)x_--;
		if(mp[x_][y_]!=-1){
			x=x_,y=y_;
			if(x==_x&&y==_y)f=1;
			if(cnt[x][y]==0){
				ans1++;
				cnt[x][y]=1;
			}
		}
		else{
			d=(d+1)%4;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			if(cnt[i][j])ans++;
//		}
//	}
	cout<<ans1-f<<endl;
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
 

