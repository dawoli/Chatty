#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
int xd[4]={0,1,0,-1};
int yd[4]={1,0,-1,0};
char rmap[1050][1050];
bool passed[1050][1050];
int ans[60];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(rmap,0,sizeof(rmap));
		memset(passed,0,sizeof(passed));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int a=1;a<=n;a++){
			for(int b=1;b<=m;b++){
				cin>>rmap[a][b];
			}
		}
		if(!passed[x][y]){
			ans[i]++;
			passed[x][y]=1;
		}
		while(k--){
			if(rmap[x+xd[d]][y+yd[d]]=='x'||x+xd[d]<1||x+xd[d]>n||y+yd[d]<1||y+yd[d]>m){
				d=(d+1)%4;
			}
			else{
				x+=xd[d];
				y+=yd[d];
			}
			if(!passed[x][y]){
				ans[i]++;
				passed[x][y]=1;
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
