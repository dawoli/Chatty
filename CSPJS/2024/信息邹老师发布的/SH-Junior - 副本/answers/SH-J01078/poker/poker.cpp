#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
bool vis[5][15];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char a,b;
		int x,y;
		cin>>a>>b;
		if(a=='D'){
			x=1;
		}
		else if(a=='C'){
			x=2;
		}
		else if(a=='H'){
			x=3;
		}
		else if(a=='S'){
			x=4;
		}
		if(b=='A'){
			y=1;
		}
		else if(b=='T'){
			y=10;
		}
		else if(b=='J'){
			y=11;
		}
		else if(b=='Q'){
			y=12;
		}
		else if(b=='K'){
			y=13;
		}
		else{
			y=b-48;
		}
		if(vis[x][y]==0){
			vis[x][y]=1;
			ans--;
		}
	}
	cout<<ans;
	return 0;
}
