#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int n,m,a[509],c[509],cnt=0,ans=0;
bool vst[509];
void dfs(int x,bool ok,int p){
	vst[x]=1;
	if(cnt>=c[x]||a[p]==0){
		cnt++;
		ok=1;
		if(cnt>n-m){
			cnt--;
			vst[x]=0;
			return;
		}
	}
	if(p==n){
		ans=(ans+1)%MOD;
		vst[x]=0;
		if(ok)cnt--;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vst[i])dfs(i,0,p+1);
	vst[x]=0;
	if(ok)cnt--;
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		int k=c-'0';
		a[i]=k;
//		cout<<a[i]<<" ";
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1,0,1);
	cout<<ans<<endl;
	return 0;
}
