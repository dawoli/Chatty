#include<bits/stdc++.h>
using namespace std;
int a[100005][3],ans;
bool b[100005];
int n;
void dfs(int ang,int y,int p,int q,int r){
	if(p*2>n or q*2>n or r*2>n){
		return;
	}
	if(y>n){
		ans=max(ans,ang);
	}
	dfs(ang+a[y][0],y+1,p+1,q,r);
	dfs(ang+a[y][1],y+1,p,q+1,r);
	dfs(ang+a[y][2],y+1,p,q,r+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		memset(a,0,sizeof(a));
	
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i][0]);
			scanf("%d",&a[i][1]);
			scanf("%d",&a[i][2]);
		}
		dfs(0,1,0,0,0);
		
		cout<<ans<<endl;
	}
	
	return 0;
}
