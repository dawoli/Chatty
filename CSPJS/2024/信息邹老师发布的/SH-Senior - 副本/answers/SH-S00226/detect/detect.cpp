#include<bits/stdc++.h>
using namespace std;
int cnt,ans,d[100005],v[100005],a[100005],p[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		sort(p+1,p+m+1);
		for(int i=1;i<=n;i++){
			if(v[i]<=V||d[i]>p[m]){
				cnt++;
			}
		}
		ans=m-1;
		cout<<cnt<<' '<<ans<<endl;
	}
	return 0;
} 
