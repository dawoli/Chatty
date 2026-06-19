#include<bits/stdc++.h>
using namespace std;
int t,n,ans,a[200005],c[200005];
void dfs(int x){
	if(x==n+1){
	  int res=0;
	  for(int i=1;i<=n;i++){
	  	for(int j=i-1;j>=1;j--){
	  	  if(c[i]==c[j]){
	  	  	if(a[i]==a[j]) res+=a[i];
	  	  	break;
		  }
		}
	  }
	  ans=max(ans,res);
	  return ;
	}
	dfs(x+1),c[x]=1;
	dfs(x+1),c[x]=0;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
	  cin>>n;
	  for(int i=1;i<=n;i++){
	  	cin>>a[i];
	  	c[i]=0;
	  }
	  ans=0;
	  dfs(1);
	  cout<<ans<<endl;
	}
	return 0;
}
