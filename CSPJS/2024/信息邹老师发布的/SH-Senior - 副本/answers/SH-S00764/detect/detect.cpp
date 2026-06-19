#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		int d[n],v[n],a[n],p[m],ma=-1;
		for(int j=0;j<n;j++){
			cin>>d[j]>>v[j]>>a[j];
		}
		for(int j=0;j<m;j++){
			cin>>p[j];
			ma=max(ma,p[j]);
		}
		if(a[0]==0){
			int ans=0;
			for(int j=0;j<n;j++){
				if(ma>=d[j]&&v[j]>V){
					ans++;
				}
			}
			cout<<ans<<" ";
			if(ans==0){
				cout<<m<<endl;
			}
			else{
				cout<<m-1<<endl;
			}
		}
		else if(a[0]>0){
			int ans=0;
			for(int j=0;j<n;j++){
				if(ma>=d[j]&&sqrt(v[j]*v[j]+2*a[j]*(ma-d[j]))>V){
					ans++;
				}
			}
			cout<<ans<<" ";
			if(ans==0){
				cout<<m<<endl;
			}
			else{
				cout<<m-1<<endl;
			}
		}
	}
	return 0;
}
