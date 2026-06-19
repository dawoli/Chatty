#include<bits/stdc++.h>
using namespace std;
int n;
int xa(char a){
	if(a=='D') return 1;
	if(a=='C') return 2;
	if(a=='H') return 3;
	if(a=='S') return 4;
}
int xb(char a){
	if(a=='A') return 1;
	if('2'<=a&&a<='9') return a-'0';
	if(a=='T') return 10;
	if(a=='J') return 11;
	if(a=='Q') return 12;
	if(a=='K') return 13;
}
bool u[10][20];
int main(){
	memset(u,0,sizeof(u));
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	string a;
	while(n--){
		cin>>a;
		u[xa(a[0])][xb(a[1])]=true;
	}
	int ans=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			if(!u[i][j])
				ans++;
	cout<<ans;
	return 0;
}
