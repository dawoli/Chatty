#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,maxs=-1,t;
int a[N][10],p[N];
void dfs(int x,int s){
	if(s>maxs) maxs=s;
	if(x==n+1){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(p[i]<n/2){
			p[i]++;
			dfs(x+1,s+a[x][i]);
			p[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		maxs=-1;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1,0);
		cout<<maxs<<"\n";
	}
	
	return 0;
}
