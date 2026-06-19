#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][4],ans=-1;
void dfs(long long x,long long y,long long z,long long k,long long sum){
	if(k>n){
		ans=max(ans,sum);
		return;
	}
	if(x<n/2){
		dfs(x+1,y,z,k+1,sum+a[k][1]);
	}
	if(y<n/2){
		dfs(x,y+1,z,k+1,sum+a[k][2]);
	}
	if(z<n/2){
		dfs(x,y,z+1,k+1,sum+a[k][3]);
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		ans=-1;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(0,0,0,1,0);
		cout<<ans<<endl;
	}
	
	return 0; 
} 
