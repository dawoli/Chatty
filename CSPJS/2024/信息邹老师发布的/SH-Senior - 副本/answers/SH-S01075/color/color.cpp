#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
int a[200005];
int red,blu;
int ans=0;
void dfs(int x,int sum){
	if(x>n){
		ans=max(ans,sum);
		return ;
	}
	int qr=red,qb=blu;
	if(a[x]==red){
		red=a[x];
		dfs(x+1,sum+red);
	}
	else{
		red=a[x];
		dfs(x+1,sum);
	}
	red=qr;
	if(a[x]==blu){
		blu=a[x];
		dfs(x+1,sum+blu);
	}
	else{
		blu=a[x];
		dfs(x+1,sum);
	}
	blu=qb;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		red=blu=ans=0;
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
} 
