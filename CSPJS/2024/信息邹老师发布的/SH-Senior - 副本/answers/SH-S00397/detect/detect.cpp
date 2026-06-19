#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,vm,ans,fst,d[100005],v[100005],a[100005],p[100005];
bool vis[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
	  cin>>n>>m>>l>>vm;
	  ans=0,fst=0;
	  for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
	  for(int i=1;i<=m;i++){
	  	cin>>p[i];
	  	fst=max(fst,p[i]);
	  }
	  for(int i=1;i<=n;i++)
	  	if(v[i]>vm&&d[i]<=fst) ans++;
	  cout<<ans<<" ";
	  if(ans==0) cout<<m<<endl;
	  else cout<<m-1<<endl;
	}
	return 0;
}
