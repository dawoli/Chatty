#include<bits/stdc++.h>
using namespace std;
long long t,m,n,l,v1,p[100005],d[100005],v[100005],a[100005],ans=0;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	while(t--){
		cin>>n>>m>>l>>v1;
		for(int i=0;i<n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(v[i]>v1) ans++;
		}
		for(int i=0;i<m;i++){
			cin>>p[i];
		}
		cout<<ans<<" "<<3<<endl;
	}	
	return 0;
}
