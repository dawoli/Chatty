#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
int n,maxxx;
long long ans;
int a[5009];
bool cmp(int x,int y){
	return x>y;
}
long long qp(long long aa,long long bb){
	if(bb==1)return aa;
	long long r=(qp(aa,bb/2))%mod;
	r=(r*r)%mod;
	if(bb%2==1)r=r*aa%mod;
	return r;
}
void dfs(int id,int cnt,int sum,int maxx){
	if(id>n){
		if(sum>maxx*2&&cnt>=3){
			ans=(ans+1)%mod;
		}
		return ;
	}
	if(sum>maxx*2&&cnt>=3){
		ans=(ans+qp(2,n-id+1))%mod;
		return ;
	}//ÒÑ¾­id,Âú×ã+,·ñÔòid+1 
	dfs(id+1,cnt+1,sum+a[id],max(maxx,a[id]));
	dfs(id+1,cnt,sum,maxx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxxx=max(maxxx,a[i]);
	}
	if(maxxx<=1){
		long long jc[5009]={};
		jc[0]=1;
		for(int i=1;i<=n;i++)jc[i]=(jc[i-1]*i)%mod;
		for(int i=3;i<=n;i++){
			ans=(ans+jc[n]/jc[n-i]/jc[i])%mod; 
		}
		cout<<ans<<'\n';
//		cout<<n<<'\n';
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	dfs(1,0,0,0);
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
