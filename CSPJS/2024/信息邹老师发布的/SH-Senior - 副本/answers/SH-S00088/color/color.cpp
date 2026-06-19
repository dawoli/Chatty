#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200009
#define M 1000009
ll T,n,a[N],ans,cnt[M],lst[N],clr[N],f[N][2];
bool ok[20];
void dfs(ll i){
	if(i==n+1){
		ll res=0;
		for(ll i=1;i<=n;i++){
			ll cnt=0;
			for(ll j=i-1;j>=1;j--){
				if(ok[i]==ok[j]){
					if(a[i]==a[j])cnt=a[i];
					break;
				}
			}
			res+=cnt;
		}
		ans=max(ans,res);
		return;
	}
	ok[i]=1;
	dfs(i+1);
	ok[i]=0;
	dfs(i+1);
}
void solbf(){
	memset(ok,0,sizeof ok);
	dfs(1);
	cout<<ans<<"\n";
}
//vector<ll>cnp[N];
//void sol(){
//	memset(lst,0,sizeof lst);
//	memset(cnt,0,sizeof cnt);
//	for(ll i=1;i<=1000000;i++)cnp[i].clear();
//	for(ll i=1;i<=n;i++){
//		if(cnt[a[i]])lst[i]=cnt[a[i]];
//		cnt[a[i]]=i;
//		cnp[a[i]].push_back(i);
//	}
//	bool frst=1;
//	for(ll i=1000000;i>=1;i--){
//		if(cnp[i].size()>1){
//			for(ll j=0;j<cnp[i].size()-1;j++){
//				if(frst)
//			}
//		}
//	}
//    for(ll i=1;i<=n;i++){
//    	if(lst[i]){
//    		if(lst[lst[i]]==)
//		}
//		f[i][1]=max(f[i-1][0],f[i-1][1]);
//	}
//}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(ll i=1;i<=n;i++)cin>>a[i];
		solbf(); 
//		else sol();
	} 
	return 0;
}
