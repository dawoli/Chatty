#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,t,n,a[200005];
bool f[200005];
void shuru(){
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>a[i]; 
}
void cal(){
	ll tmp=0;
	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0;j--)
		    if(f[i]==f[j]){
		    	if(a[i]==a[j])
		    	    tmp+=a[i];
		    	break;
			}
	}
	ans=max(tmp,ans);
}
void dfs(ll x){
	if(x==n-1){
		cal();
		return;
	}
	f[x+1]=1;
	dfs(x+1);
	f[x+1]=0;
	dfs(x+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(ll i=0;i<t;i++){
		shuru();
		ans=0;
		dfs(0);
		cout<<ans;
		if(i!=t-1)
		    cout<<endl;
	}		
	fclose(stdin);
	fclose(stdout);
	return 0;  
}
