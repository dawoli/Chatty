#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p=998244353;
ll a[5005],n,ans,fact[700]={1,};
void dfs(int d,int mx,int sum){
	for(int i=d+1;i<=n;i++){
		dfs(i,max(mx,a[i]),sum+a[i]);
	}
	if(sum>2*mx){
		ans=(ans+1)%p;
		return;
	}
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=1) flag=false;
	}
	dfs(0,0,0);
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
	return 0;
}

