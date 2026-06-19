#include <bits/stdc++.h>
using namespace std;
int vis[20][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=52;
	cin>>n;
	while(n--){
		char a,b;
		cin>>a>>b;
		if(a=='H') a-=69;
		else if(a=='S') a-=79;
		else a-=66;
		if(b=='A') b-=64;
		else if(b=='T') b-=74;
		else if(b=='J') b-=63;
		else if(b=='Q') b-=69;
		else if(b=='K') b-=62;
		else b-=48;
		vis[a][b]++;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(vis[i][j]) ans--;
		}
	}
	cout<<ans;
	return 0;
}
