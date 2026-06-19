#include<bits/stdc++.h>
using namespace std;
int n,c[7][15],m,mm2,ans;
char a[55],b[55];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		if(b[i]=='A') m=1;
		else if(b[i]=='T') m=10;
		else if(b[i]=='J') m=11;
		else if(b[i]=='Q') m=12;
		else if(b[i]=='K') m=13;
		else if(b[i]>='2'&&b[i]<='9') m=b[i]-'0';
		if(a[i]=='D') mm2=1;
		else if(a[i]=='C') mm2=2;
		else if(a[i]=='H') mm2=3;
		else if(a[i]=='S') mm2=4;
		c[mm2][m]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(c[i][j]==0){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
