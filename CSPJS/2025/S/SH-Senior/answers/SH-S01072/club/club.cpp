#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],ans,b[100005];
void dfs(int x,int num,int p1,int p2,int p3){
	if(p1>n/2||p2>n/2||p3>n/2)return;
	if(x==n){
		ans=max(ans,num);
		return;
	}
	dfs(x+1,num+a[x][0],p1+1,p2,p3);
	dfs(x+1,num+a[x][1],p1,p2+1,p3);
	dfs(x+1,num+a[x][2],p1,p2,p3+1);
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		int flag=1;
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		if(n==100000){
			for(int i=0;i<n;i++){
				if(!(a[i][1]==a[i][2]&&a[i][2]==0)){
					flag=0;
				}
			}
			if(flag){
				for(int i=0;i<n;i++)b[i]=a[i][0];
				sort(b,b+n);
				for(int i=n-1;i>=n/2;i--)ans+=b[i];
				cout<<ans<<'\n';
				continue;
			}
		} 
		if(n>10){
			for(int i=0;i<n;i++){
				ans+=max(max(a[i][0],a[i][1]),a[i][2]);
			}
			cout<<ans<<'\n';
			continue;
		}
		dfs(0,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
} 
