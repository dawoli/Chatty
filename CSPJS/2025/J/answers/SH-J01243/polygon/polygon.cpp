#include<bits/stdc++.h>
using namespace std;
int n,a[5005],length,ans,C[5005];
const int MOD=998244353;
bool flag;
void dfs(int length,int longest,int now){
	if(length>2*longest) {
		ans++;
		ans%=MOD;
	}
	if(now==n) return ;
	for(int i=now+1;i<=n;i++){
		dfs(length+a[i],max(longest,a[i]),i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false; 
	}
	if(flag){
		for(int i=3;i<=n;i++)
		{
			C[i]+=C[i-1];
			C[i]+=((n-2)*(n-1)*n)/6;
			C[i]%=MOD; 
		}
		cout<<C[n]<<endl;
	}
	else{
		dfs(0,0,0);
		cout<<ans<<endl;
	}
}
