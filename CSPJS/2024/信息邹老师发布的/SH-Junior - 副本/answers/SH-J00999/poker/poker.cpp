#include<bits/stdc++.h>
using namespace std;
bool has[4][14];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,x,y;
	char a[5];
	cin >> n;
	int ans=52;
	for(int i=0;i<n;i++){
		cin >> a;
		if(a[0]=='D') x=0;
		if(a[0]=='C') x=1;
		if(a[0]=='H') x=2;
		if(a[0]=='S') x=3;
		if(a[1]>='2'&&a[1]<='9')y=a[1]-'0';
		if(a[1]=='A') y=1;
		if(a[1]=='T') y=10;
		if(a[1]=='J') y=11;
		if(a[1]=='Q') y=12;
		if(a[1]=='K') y=13;
		if(!has[x][y])ans--;
		has[x][y]=1;
	}
	cout << ans;
	//fclose()
	return 0;
}
