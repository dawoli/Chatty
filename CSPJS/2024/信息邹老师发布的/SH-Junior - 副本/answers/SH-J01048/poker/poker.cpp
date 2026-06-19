#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[10][20],ans,aa;
char x,y;
signed main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		if(x=='D'){
			aa=1;
			if(y=='A')if(0==a[aa][1])a[aa][1]++,ans++;
			if(y=='T')if(0==a[aa][10])a[aa][10]++,ans++;
			if(y=='J')if(0==a[aa][11])a[aa][11]++,ans++;
			if(y=='Q')if(0==a[aa][12])a[aa][12]++,ans++;
			if(y=='K')if(0==a[aa][13])a[aa][13]++,ans++;
			if(y>='2'&&y<='9')if(0==a[aa][y-'0'])a[aa][y-'0']++,ans++;
		}
		if(x=='C'){
			aa=2;
			if(y=='A')if(0==a[aa][1])a[aa][1]++,ans++;
			if(y=='T')if(0==a[aa][10])a[aa][10]++,ans++;
			if(y=='J')if(0==a[aa][11])a[aa][11]++,ans++;
			if(y=='Q')if(0==a[aa][12])a[aa][12]++,ans++;
			if(y=='K')if(0==a[aa][13])a[aa][13]++,ans++;
			if(y>='2'&&y<='9')if(0==a[aa][y-'0'])a[aa][y-'0']++,ans++;
			
		}
		if(x=='H'){
			aa=3;
			if(y=='A')if(0==a[aa][1])a[aa][1]++,ans++;
			if(y=='T')if(0==a[aa][10])a[aa][10]++,ans++;
			if(y=='J')if(0==a[aa][11])a[aa][11]++,ans++;
			if(y=='Q')if(0==a[aa][12])a[aa][12]++,ans++;
			if(y=='K')if(0==a[aa][13])a[aa][13]++,ans++;
			if(y>='2'&&y<='9')if(0==a[aa][y-'0'])a[aa][y-'0']++,ans++;
			
		}
		if(x=='S'){
			aa=4;
			if(y=='A')if(0==a[aa][1])a[aa][1]++,ans++;
			if(y=='T')if(0==a[aa][10])a[aa][10]++,ans++;
			if(y=='J')if(0==a[aa][11])a[aa][11]++,ans++;
			if(y=='Q')if(0==a[aa][12])a[aa][12]++,ans++;
			if(y=='K')if(0==a[aa][13])a[aa][13]++,ans++;
			if(y>='2'&&y<='9')if(0==a[aa][y-'0'])a[aa][y-'0']++,ans++;
			
		}
	}
	cout<<52-ans;
	return 0;
}
