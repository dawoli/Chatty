#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n,m,L,V;
	cin>>n>>m>>L>>V;
	int d[100001],v[100001],a[100001],p[100001];
	for(int i=1;i<=n;i++){
		cin>>d[i]>>v[i]>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>p[i];
	}
	sort(p+1,p+m+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(d[i]>p[j])
				continue;
			else if(a[i]==0){
				if(v[i]>V){
					ans++;
					break;
				}
			}
			else{
				if(sqrt((p[j]-d[i])*a[i]*2+v[i]*v[i])>V){
					ans++;
					break;
				}
			}
		}
	}
	cout<<ans<<" "<<m-2<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		solve();
	}
	return 0;
}
