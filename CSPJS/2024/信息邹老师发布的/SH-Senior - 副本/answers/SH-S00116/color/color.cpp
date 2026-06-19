#include<iostream>
using namespace std;
const int N=2e5+4;
int n,a[N],ans,res[N];
bool c[N];
int calc(){
	int sum=0;
	for(int i=1;i<=n;++i){
		for(int j=i-1;j>=1;--j)
			if(c[i]==c[j]){
				if(a[i]==a[j]) sum+=a[i]; 
				break;
			} 
	}
	return sum;
}
void dfs(int now){
	if(now>n){
		ans=max(ans,calc());
		return ;
	}
	c[now]=1;
	dfs(now+1);
	c[now]=0;
	dfs(now+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T; cin>>T;
	while(T--){
		for(int i=1;i<=n;++i) res[i]=c[i]=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i];
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
