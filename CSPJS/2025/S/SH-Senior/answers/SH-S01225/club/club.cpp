#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][15],x,y,z,n,xian,ans;
void dfs(int wz,int x,int y,int z,int cnt) {
	if(wz>n) return ;
	
	if(x>xian||y>xian||z>xian) return ;
	if(x+y+z==n)  {
		ans=max(cnt,ans);
		return ;
	}
	for(int i=wz;i<=n;i++) {
		dfs(i+1,x+1,y,z,cnt+a[i][1]);
		dfs(i+1,x,y+1,z,cnt+a[i][2]);
		dfs(i+1,x,y,z+1,cnt+a[i][3]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		ans=0;cin>>n;xian=n/2;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
