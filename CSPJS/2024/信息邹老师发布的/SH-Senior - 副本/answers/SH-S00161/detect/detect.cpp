#include<bits/stdc++.h>
using namespace std;
int t,d[100005],v[100005],a[100005],p[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		int n,m,l,va,ans=0;
		cin>>n>>m>>l>>va;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			if(d[i]>p[m]||v[i]<=va) continue;
			else ans++;
		}
		cout<<ans<<" ";
		if(ans==0) {
			cout<<m<<endl;
		}
		else cout<<m-1<<endl;
	}
	return 0;
} 
