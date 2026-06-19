#include<bits/stdc++.h>
using namespace std;
int rcost[102000];
int rs[102000];
int re[102000];
bool light[10200];
int city[10200][10200];
int mi[10010][20];
int opo[20];
int n,m,k;
long long cnt=0,mini=1000000000;
void dfs(int g,int k){
	int mc=1000000,mmc;
	if(g==k){
		mini=min(mini,cnt);
		return;
	}
	for(int i=1;i<=n;i++){
		if(city[g][i]!=0){
			light[i]=1;
			dfs(i,k+1);
			cnt+=rcost[i];
			light[i]=0;
			cnt-=rcost[i];
	} 
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>rs[i]>>re[i]>>rcost[i];
		city[rs[i]][re[i]]=rcost[i];
	}
	for(int i=1;i<=k;i++){
		cin>>opo[i];
		for(int j=1;j<=n;j++){
			cin>>mi[j][i];
		}
		
	}
	dfs(1,0);
	cout<<mini;
	fclose(stdin);
	fclose(stdout);
} 
