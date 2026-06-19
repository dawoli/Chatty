#include<iostream>
using namespace std;
typedef long long ll;
bool block[1003][1003],vis[1003][1003];
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ll t;
	cin>>t;
	while(t--) {
		ll n,m,k,x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		for(ll i=1;i<=n;i++) {
			string s;
			cin>>s;
			for(ll j=1;j<=m;j++) vis[i][j]=0,block[i][j]=(s[j-1]=='x');
		}
		ll cnt=1;
		vis[x][y]=1;
		while(k--) {
			ll X,Y;
			if(d==0) X=x,Y=y+1;
			if(d==1) X=x+1,Y=y;
			if(d==2) X=x,Y=y-1;
			if(d==3) X=x-1,Y=y;
			if(1<=X&&X<=n&&1<=Y&&Y<=m&&!block[X][Y]) {
				x=X,y=Y;
				if(!vis[x][y]) cnt++,vis[x][y]=1;
			}
			else d=(d+1)%4;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
