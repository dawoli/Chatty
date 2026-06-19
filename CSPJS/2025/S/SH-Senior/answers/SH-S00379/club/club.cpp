#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int a[N][5],n,t,m,maxn=0;
void dfs(int i,int sum,int x,int y,int z,int j){
	if(x>m or y>m or z>m) return ;
	if(i==n+1){
		maxn=max(maxn,sum);
		return ;
	}else{
		dfs(i+1,sum+a[i][j],x+1,y,z,1);
		dfs(i+1,sum+a[i][j],x,y+1,z,2);
		dfs(i+1,sum+a[i][j],x,y,z+1,3);
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		m=n/2;
		dfs(0,0,0,0,0,0);
		cout << maxn << endl;
		maxn=0;
	}
	return 0;
}

