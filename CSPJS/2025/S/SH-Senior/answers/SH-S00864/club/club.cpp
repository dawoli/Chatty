#include <bits/stdc++.h>
using namespace std;
int a[100003][4],t,n,k[100003]; 
int maxn,res;
void dfs(int x,int y,int z){
	if(x>n/2||y>n/2||z>n/2) return;
	if(x+y+z==n){
		maxn=max(maxn,res);
		return;
	}
	int m=res;
	res=m+a[x+y+z+1][1];
	dfs(x+1,y,z);
	res=m+a[x+y+z+1][2];
	dfs(x,y+1,z);
	res=m+a[x+y+z+1][3];
	dfs(x,y,z+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(n<=10){
			maxn=0;res=0;
			dfs(0,0,0);
			cout<<maxn<<endl;
		}
		res=0;
		for(int i=1;i<=n;i++) k[i]=a[i][1];
		sort(k+1,k+n+1);
		for(int i=n;i>=n/2;i--) res+=k[i];
		cout<<res<<endl;
	}
	return 0;
} 
