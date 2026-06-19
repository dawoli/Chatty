#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int cnt;
bool vis[105][105];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char ca,cb;
		int x,y;
		cin>>ca>>cb;
		if(ca=='D')x=1;
		if(ca=='C')x=2;
		if(ca=='H')x=3;
		if(ca=='S')x=4;
		if(cb=='2')y=2;
		if(cb=='3')y=3;
		if(cb=='4')y=4;
		if(cb=='5')y=5;
		if(cb=='6')y=6;
		if(cb=='7')y=7;
		if(cb=='8')y=8;
		if(cb=='9')y=9;
		if(cb=='A')y=1;
		if(cb=='T')y=10;
		if(cb=='J')y=11;
		if(cb=='Q')y=12;
		if(cb=='K')y=13;
		vis[x][y]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(vis[i][j]==0) cnt++;
//			cout<<vis[i][j]<<" ";
		}
//		cout<<"\n";
	}
	cout<<cnt;
	return 0;
}
