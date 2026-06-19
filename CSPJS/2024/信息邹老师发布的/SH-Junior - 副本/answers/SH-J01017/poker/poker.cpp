#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt=0;
bool vis[4][13];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<=3;i++)
		for(int j=0;j<=12;j++)
			vis[i][j]=0;
	for(int i=0;i<=n-1;i++){
		char a,b;
		ll c,d;
		cin>>a>>b;
		if(a=='D')
			c=0;
		if(a=='C')
			c=1;
		if(a=='H')
			c=2;
		if(a=='S')
			c=3;
		if(b=='A')
			d=0;
		if(b=='2')
			d=1;
		if(b=='3')
			d=2;
		if(b=='4')
			d=3;
		if(b=='5')
			d=4;
		if(b=='6')
			d=5;
		if(b=='7')
			d=6;
		if(b=='8')
			d=7;
		if(b=='9')
			d=8;
		if(b=='T')
			d=9;
		if(b=='J')
			d=10;
		if(b=='Q')
			d=11;
		if(b=='K')
			d=12;
		vis[c][d]=1;
	}
	for(int i=0;i<=3;i++)
		for(int j=0;j<=12;j++)
			if(vis[i][j]==0)
				cnt++;
	cout<<cnt;
	return 0;
}
