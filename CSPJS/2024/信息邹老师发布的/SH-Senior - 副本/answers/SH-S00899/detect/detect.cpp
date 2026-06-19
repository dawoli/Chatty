#include<bits/stdc++.h>
using namespace std;

int T,n,m,L,V,ans;
int d[100005],v[100005],a[100005],p[100005];

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int j=0;j<T;j++){
		cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=0;i<m;i++){
			cin>>p[i];
		}
		sort(p,p+m);
		if(v[1]>V){
			 for(int i=0;i<n;i++){
			 	if(d[i]>p[m-1]){
			 		continue;
				 }
				 ans++;
			 }
			 cout<<ans<<" "<<m-1<<endl;
		}
		else{
			cout<<0<<m<<endl;
		}
	}
	return 0;
}
