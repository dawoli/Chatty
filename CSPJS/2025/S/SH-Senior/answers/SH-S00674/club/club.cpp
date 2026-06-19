#include<bits/stdc++.h>
using namespace std;

struct node{
	int a,b,c;
}m[200010];
int _;
int vis[200010];
int ans[200010];
int maxn;
void dfs(int t,int n,int a1,int b1,int c1,int a2,int b2,int c2){
	if(t==n+1){
		maxn=max(maxn,a1+b1+c1);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1&&a2<n/2){
			dfs(t+1,n,a1+m[t].a,b1,c1,a1+1,b2,c2);
		}
		if(i==2&&b2<n/2){
			dfs(t+1,n,a1,b1+m[t].b,c1,a2,b2+1,c2);
		}
		if(i==3&&c2<n/2){
			dfs(t+1,n,a1,b1,c1+m[t].c,a2,b2,c2+1);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> _;
	while(_--){
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> m[i].a >> m[i].b >> m[i].c;
			vis[i]=0;
			ans[i]=0;
		}
		dfs(1,n,0,0,0,0,0,0);
		cout << maxn<<endl;
		maxn=0;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

