#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const maxn=0x3f3f3f3f;
ll ans=maxn,k,n,m,a[10]={6,2,5,5,4,5,6,3,7,6};
void dfs(ll step,ll tot,ll num){
	if(tot==0){
		ans=min(ans,num);
		return;
	}
	if(tot>step*7)return;
	if(tot<step*2)return;
	for(int i=0;i<=9;i++){
		if(i==0&&step==m)continue;
		if(tot<a[i])continue;
		dfs(step-1,tot-a[i],num*10+i);
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);ans=maxn;
		if(k%7==0&&k>=7){
			for(int j=1;j<=k/7;j++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}else if(k%7==1&&k>=8){
			k-=8;cout<<10;
			for(int j=1;j<=k/7;j++)cout<<8;
			cout<<endl;
			continue;
		}else{
			m=k/7+(k%7!=0);
			dfs(m,k,0);
		}
		if(ans==maxn)cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
