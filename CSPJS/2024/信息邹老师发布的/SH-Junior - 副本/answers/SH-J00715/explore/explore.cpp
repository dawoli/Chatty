#include<bits/stdc++.h>
using namespace std;
int n,m;
bool ditu[1001][1001];
bool zuji[1001][1001];
void dfs(int xianzaix1,int xianzaiy1,int k,int d){
	zuji[xianzaix1][xianzaiy1]=1;
	if(k==0) return;
	int xiabux,xiabuy;
	if(d==0){
		xiabux=xianzaix1;
		xiabuy=xianzaiy1+1;
		if(!(1<=xiabux<=n)||!(1<=xiabuy<=m)||ditu[xiabux][xiabuy]==0) dfs(xianzaix1,xianzaiy1,k-1,(d+1)%4);
		else{
			dfs(xiabux,xiabuy,k-1,d);
		}
	}
	else if(d==1){
		xiabux=xianzaix1+1;
		xiabuy=xianzaiy1;
		if(!(1<=xiabux<=n)||!(1<=xiabuy<=m)||ditu[xiabux][xiabuy]==0) dfs(xianzaix1,xianzaiy1,k-1,(d+1)%4);
		else dfs(xiabux,xiabuy,k-1,d);
	}
	else if(d==2){
		xiabux=xianzaix1;
		xiabuy=xianzaiy1-1;
		if(!(1<=xiabux<=n)||!(1<=xiabuy<=m)||ditu[xiabux][xiabuy]==0) dfs(xianzaix1,xianzaiy1,k-1,(d+1)%4);
		else dfs(xiabux,xiabuy,k-1,d);
	}
	else{
		xiabux=xianzaix1-1;
		xiabuy=xianzaiy1;
		if(!(1<=xiabux<=n)||!(1<=xiabuy<=m)||ditu[xiabux][xiabuy]==0) dfs(xianzaix1,xianzaiy1,k-1,(d+1)%4);
		else dfs(xiabux,xiabuy,k-1,d);
	}
	
}
int main(){
	int T;
	int k,d;
	int x11,y11;
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		for(int i=1;i<=1000;i++){
			for(int j=1;j<=1000;j++){
				zuji[i][j]=0;
			}
		}
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x11,&y11,&d);
		char aaa;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>aaa;
				if(aaa=='x') ditu[i][j]=0;
				else ditu[i][j]=1;
			}
		}
		int cnt=0;
		dfs(x11,y11,k,d);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(zuji[i][j]) cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	
}
