#include<bits/stdc++.h>
using namespace std;
bool vis[14][5];
int hua(char c){
	if(c=='D'){
		return 1;
	}
	else if(c=='C'){
		return 2;
	}
	else if(c=='H'){
		return 3;
	}
	else if(c=='S'){
		return 4;
	}
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		char x,y;
		cin>>y>>x;
		if(x=='A'){
			vis[1][hua(y)]=1;
		}
		else if(x=='T'){
			vis[10][hua(y)]=1;
		}
		else if(x=='J'){
			vis[11][hua(y)]=1;
		}
		else if(x=='Q'){
			vis[12][hua(y)]=1;
		}
		else if(x=='K'){
			vis[13][hua(y)]=1;
		}
		else vis[int(x-'0')][hua(y)]=1;
	}
	for(int i=1;i<=13;i++){
		for(int j=1;j<=4;j++){
			if(vis[i][j])ans++;
		}
	}
	cout<<52-ans;	
	return 0;
}
