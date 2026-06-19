#include <bits/stdc++.h>
using namespace std;

int n,ans;
int num[5][15];

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	char a,b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		int cnt1,cnt2;
		if(a=='D') cnt1=1;
		else if(a=='C') cnt1=2;
		else if(a=='H') cnt1=3;
		else if(a=='S') cnt1=4;
		if(b=='T') cnt2=10;
		else if(b=='A') cnt2=1;
		else if(b=='J') cnt2=11;
		else if(b=='Q') cnt2=12;
		else if(b=='K') cnt2=13;
		else cnt2=b-'0';
		num[cnt1][cnt2]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(num[i][j]==0) ans++;
		}
	}
	cout<<ans;
	return 0;
}
