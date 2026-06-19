#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,x,y,k,d,ans=0,cnt=0,b;
char a[N][N];
//int dfs(int x,int y,int d,int k){
//	if(k==1){
//		return cnt;
//	}
//	if(d==0){
//		if(a[x][y+1]=='.'){
//			cnt++;
//			return dfs(x,y+1,d,k-1);
//		}
//		if(a[x][y+1]=='x'||x<1||x>b||y<1||y>m){
//			ans++;
//			return dfs(x,y,(d+1)%4,k-1);
//		}
//	}
//	if(d==1){
//		if(a[x+1][y]=='.'){
//			cnt++;
//			return dfs(x+1,y,d,k-1);
//		}
//		if(a[x+1][y]=='x'||x<1||x>b||y<1||y>m){
//			return dfs(x,y,(d+1)%4,k-1);
//		}
//	}
//	if(d==2){
//		if(a[x][y-1]=='.'){
//			cnt++;
//			return dfs(x,y-1,d,k-1);
//		}
//		if(a[x][y-1]=='x'||x<1||x>b||y<1||y>m){
//			ans++;
//			return dfs(x,y,(d+1)%4,k-1);
//		}
//	}
//	if(d==3){
//		if(a[x-1][y]=='.'){
//			cnt++;
//			return dfs(x-1,y,d,k-1);
//		}
//		if(a[x-1][y]=='x'||x<1||x>b||y<1||y>m){
//			ans++;
//			return dfs(x,y,(d+1)%4,k-1);
//		}
//	}
//}
int main(){
	freopen("explore","r",stdin);
	freopen("freopen","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>m>>k;
		cin>>x>>y>>d;
		for(int j=1;j<=b;j++){
			for(int z=1;z<=m;z++){
				cin>>a[i][j];
			}
		}
		cout<<k;
		ans=0;
		cnt=0;
	}
}
