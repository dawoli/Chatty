#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][20];
int main(){
	freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(a,0,sizeof(a));
    cin>>n;
    for(int i=1;i<=n;i++){
    	char x,y;
    	cin>>x>>y;
    	if(x=='D'){
    		int t;
    		if(y=='A')t=1;
    		if(y=='T')t=10;
    		if(y=='J')t=11;
    		if(y=='Q')t=12;
    		if(y=='K')t=13;
    		if(y>='0' && y<='9')t=y-'0';
    		a[1][t]=1;
		}
		if(x=='C'){
    		int t;
    		if(y=='A')t=1;
    		if(y=='T')t=10;
    		if(y=='J')t=11;
    		if(y=='Q')t=12;
    		if(y=='K')t=13;
    		if(y>='0' && y<='9')t=y-'0';
    		a[2][t]=1;
		}
		if(x=='H'){
    		int t;
    		if(y=='A')t=1;
    		if(y=='T')t=10;
    		if(y=='J')t=11;
    		if(y=='Q')t=12;
    		if(y=='K')t=13;
    		if(y>='0' && y<='9')t=y-'0';
    		a[3][t]=1;
		}
		if(x=='S'){
    		int t;
    		if(y=='A')t=1;
    		if(y=='T')t=10;
    		if(y=='J')t=11;
    		if(y=='Q')t=12;
    		if(y=='K')t=13;
    		if(y>='0' && y<='9')t=y-'0';
    		a[4][t]=1;
		}
	}
	int ans=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(a[i][j]==0)ans++;
		}
	} 
	cout<<ans;
	return 0;
}

