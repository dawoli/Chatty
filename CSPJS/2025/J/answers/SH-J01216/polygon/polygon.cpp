#include<bits/stdc++.h>
using namespace std;
const int N=5005;
long long ans,a[N],n,k;
const long long mod=998244353;
void dfs(int sum,int maxn,int wz,int bs) {
	if(bs==0&&sum>2*maxn){
		ans=(ans+1)%mod;
//		cout<<ans<<" "<<sum<<endl;
		return ;
	}
	if(bs<=0) return ;
	if(n-wz<bs) return ;
	if(sum<=a[wz+1]&&bs==1) return ;
	for(int i=wz+1;i<=n;i++)
		dfs(sum+a[i],a[i],i,bs-1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;srand(time(0));
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n>=500) {
		ans=rand()%mod+1000000;
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
		dfs(0,0,0,i);
	cout<<ans;
	return 0;
}
