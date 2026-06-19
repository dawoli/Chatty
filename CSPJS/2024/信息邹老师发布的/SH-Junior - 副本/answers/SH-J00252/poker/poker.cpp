#include<bits/stdc++.h>
using namespace std;
int n,a[60][5],ans;
char c,x;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c>>x;
		if(x=='A') x=1;
		else if(x=='T') x=10;
		else if(x=='J') x=11;
		else if(x=='Q') x=12;
		else if(x=='K') x=13;
		else x-='0';
		if(c=='D') c=1;
		else if(c=='C') c=2;
		else if(c=='H') c=3;
		else if(c=='S') c=4;
		a[x][c]++;
	}
	for(int i=1;i<=13;i++)
		for(int j=1;j<=4;j++)
			if(!a[i][j]) ans++;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
