#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,a[100005],b[100005],sum,ans,p[2];
void dfs(ll x){
	if(x==n+1){
		sum=p[0]=p[1]=0;
		for(ll i=1;i<=n;i++){
			if(p[b[i]]&&a[i]==a[p[b[i]]]){
				sum+=a[i];
			}
			p[b[i]]=i;
		}
		ans=max(ans,sum);
		return;
	}
	b[x]=1;
	dfs(x+1);
	b[x]=0;
	dfs(x+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
    	cin>>n;
    	for(ll i=1;i<=n;i++){
    		cin>>a[i];
		}
		ans=0;
		dfs(1);
		cout<<ans<<endl;
	}
    return 0;
}

