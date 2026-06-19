#include <bits/stdc++.h>
using namespace std;
int t,n,sum;
struct node{
	int x,y,z;
};
node s[100010];
void dfs(int depth,int a,int b,int c,int ans){
	if(depth==n+1){
		if(ans>sum){
			sum=ans;
		}
		return;
	}
	if(a>=1){
		dfs(depth+1,a-1,b,c,ans+s[depth].x);
	}
	if(b>=1){
		dfs(depth+1,a,b-1,c,ans+s[depth].y);
	}
	if(c>=1){
		dfs(depth+1,a,b,c-1,ans+s[depth].z);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].x>>s[i].y>>s[i].z;
		}
		dfs(1,n/2,n/2,n/2,0);
		cout<<sum<<endl;
	} 
}
